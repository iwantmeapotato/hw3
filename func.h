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

  int function(string expr) { //numerical evaluation
    stack<long long int> numbers;
    stack<char> operators;
    istringstream ss(expr);
    int tmp_i; char tmp_c;
    while (!ss.eof()) {
      if (ss.peek() >= '0' && ss.peek() <= '9') {
        ss >> tmp_i;
        numbers.push(tmp_i);
      }
      else {
        ss >> tmp_c;
        if (tmp_c == '(') { //recurse
          string subf = "";
          while (tmp_c != ')') {
            ss >> tmp_c;
            if (tmp_c != ')') subf += tmp_c;
            if (ss.eof()) throw -1;
          }
          numbers.push(function(subf));
        }
        else operators.push(tmp_c);
      }
    }

    //eval stacks



    return numbers.top->data;
  }


  string evaluate() {
    function(s_exp);
    int result;
    try {
      result = function(s_exp);
    }
    catch(...) { return "error"; }

    return original + "=" + to_string(result);
  }


};
