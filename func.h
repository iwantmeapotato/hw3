#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include<cassert>
#include<cmath>
#include"ArgumentManager.h"
#define yeet delete
#define yell cout
#define MAX_ELS 1000
#define POSTFIX true
#define STRING false
using namespace std;

template<class T>
class node {
public:
  T data;
  bool negative;
  node <T>*next;
  node(T data, bool n, node *next = 0) : data(data), negative(n), next(next) {}
};

template<class T>
class stack {
public:
  node <T>*top;
  bool open;
  stack <T>() : top(0), open(0) {};

  bool empty() { if (top == 0) return true; return false; }

  void push(T data, bool neg = 0) {
    node<T> *tmp = new node<T>(data, neg, top);
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
      yell << cu->data << " ";
      cu = cu->next;
    }
  }
  void rprint() {//
    reverse(); print(); reverse();
  }
};
int priority(char x) {
  if (x == '^') return 3;
  else if (x == '*' || x == '/') return 2;
  else if (x == '+' || x == '-') return 1;
  else if (x == '(') return 0;
  return -69;
}

class expression{
  string s_exp; //og if pass by ref.
  stack<string> post_exp;
public:
  expression(string ex) : s_exp(ex) {
    function();
  }

  bool straighten() {
    char curr, prev;

    stringstream ss(s_exp);
    while (ss >> curr) {
      //if adjacent ()() then *

      prev = curr;
    }

    return false;
  }

  int function() { //numerical evaluation
    stack<char> operators;
    istringstream ss(s_exp);
    long long int stream_i; char stream_c, s_top;

    //create postfix
    while (!ss.eof()) {
      if (ss.peek() >= '0' && ss.peek() <= '9') { //is a number
        ss >> stream_i;
        post_exp.push(to_string(stream_i), 0);
      }

      else {  ///is an operator
        ss >> stream_c; if (ss.eof()) break; //don't know why but this is needed
        if (operators.empty() || stream_c == '(') operators.push(stream_c);
        else if (stream_c == ')') {  //if close parens
          while (operators.top->data != '(') {  //pop until find the open
            post_exp.push(string(1, operators.pop()));
          }
          operators.pop();
        }
        else {  ///functional operators
          s_top = operators.top->data;
          while(!operators.empty() && priority(stream_c) <= priority(s_top)) {
            s_top = operators.pop();
            post_exp.push(string(1, s_top));
            if (!operators.empty()) s_top = operators.top->data;
          } //sure to reset top->data so while() condition can compare the popped op with the correct next one
          operators.push(stream_c);
        }
      }
    }
    while(!operators.empty()) post_exp.push(string(1,operators.pop())); //out of #s, dump the rest

    return 0;
  }

  long long int evaluate() {
    stack<long long int> numbers;
    stack<char> operators;
    char op;
    long long int a, b;

    post_exp.reverse();
    while(!post_exp.empty()) {  //final element
      char testchar = post_exp.top->data[0];
      // yell << "\nleft: "; post_exp.print(); yell << "\nnums: "; numbers.rprint(); yell << '\n';
      if ((testchar >= '0' && testchar <= '9')) {
        numbers.push(stoll(post_exp.pop()));
      }
      else {
        b = numbers.pop(); a = numbers.pop();
        op = post_exp.pop()[0];
        // yell << "doing " << a << op << b << '\n';
        if (op == '^' || op == '$') numbers.push(pow(a,b));
        else if (op == '*') numbers.push(a*b);
        else if (op == '/') numbers.push(a/b);
        else if (op == '+') numbers.push(a+b);
        else if (op == '-') numbers.push(a-b);
      }
    }
    return numbers.top->data;
  }

  void print(bool postfix = STRING) {
    if (postfix) {
      post_exp.rprint();
    }
    else yell << s_exp;
  }

};
