#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include<cassert>
#include"ArgumentManager.h"
#define yeet delete
#define nut cout
#define ERROR 6969
using namespace std;

template<class T>
class node {
public:
  T data;
  node <T>*next;
  node(T data, node *next = 0) : data(data), next(next) {}
};

template<class T>
class stack {
public:
  node <T>*top;
  bool open;
  stack <T>() : top(0), open(0) {};

  bool empty() { if (top == 0) return true; return false; }

  void push(T data) {
    node<T> *tmp = new node<T>(data, top);
    top = tmp;
  }

  T pop() {
    node<T> *tmp = top;
    T x = tmp->data;
    top = tmp->next;
    yeet tmp;
    return x;
  }

  void reverse() {
    stack<T> rvd;
    while(!empty()) {
      rvd.push(pop());
    }
    top = rvd.top;
  }

  void print() {  //without popping from stack
    node<T> *cu = top;
    while(cu != 0) {
      nut << cu->data << ' ';
      cu = cu->next;
    }
  }
};


class expression{
  string original, s_exp; //og if pass by ref.
public:
  expression(string ex) : original(ex), s_exp(ex) {

  }

  string simplify(string expr) { //get rid of parentheses
    istringstream ss(expr);
    string simplified = "", subfunc = "";

    char tmp;
    while(ss >> tmp) {
      cout << "  step: " << simplified << '\n';
      if (tmp == '(') {
        
      }

      else simplified += tmp;
    }


    cout << "simplified: " << simplified << "\n\n";
    return simplified;
  }

  int function(string expr) { //numerical evaluation
    cout << "\n\nNEW FUNCTION: " << expr << "\n\n";
    stack<long long int> numbers;
    stack<char> operators;
    istringstream ss(expr);
    int tmp_i; char tmp_c;

    //simplify into stacks
    while (!ss.eof()) {
      if (ss.peek() >= '0' && ss.peek() <= '9') {
        ss >> tmp_i;
        numbers.push(tmp_i);
      }

      else {
        ss >> tmp_c;

        //if open parens
        if (tmp_c == '(') { //recurse
          int sf_open = 0;
          string subf = "";
          while (!ss.eof()) {
            ss >> tmp_c;  //after opening paren

            if (tmp_c == '(') {
              sf_open++;
              subf += tmp_c;
            }

            else if (tmp_c == ')') {
              sf_open--;
              if (sf_open <= -1) { //outermost
                numbers.push(function(subf));
                subf = "";
                sf_open = 0;
                ss >> tmp_c;
                // break;
              }
              else subf += tmp_c;
            }

            else { subf += tmp_c; }

            cout << "\ncurrent string: " << expr << "\nsubf = " << subf << "\nsf_open = " << sf_open << ", tmp_c = " << tmp_c << '\n';
            system("pause");

            if (sf_open == 0 && tmp_c == ')') break;
          }
          // if (ss.eof()) throw -1;
          nut << "\nsubfunction: " << subf << '\n';
          numbers.push(function(subf));
        }

        //else its an operator
        else operators.push(tmp_c);
      }

      cout << string(3, '\n');
    }
    //eval stacks
    cout << "\nFUNCTION CLOSED, RETURNING " << numbers.top->data << "\n";
    return numbers.top->data;
  }


  string evaluate() {
    simplify(s_exp);
    /*
    function(s_exp);
    int result;
    try {
      result = function(s_exp);
    }
    catch(...) { return "error"; }
    return original + "=" + to_string(result);
    */
    return "";
  }


};
