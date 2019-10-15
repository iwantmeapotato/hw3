#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include<cassert>
#include"ArgumentManager.h"
#define yeet delete
#define nut cout
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

/*
template<class T>
void reverse(stack<T> &in) {
  static stack<T> rvsd;
  while(!in.empty()){
    int tmp = in.pop();
    nut << "pop & push " << tmp << '\n';
    rvsd.push(tmp);
  }
  in = rvsd;
}
*/

template<class T>
class expression{
  string exp;
public:
  expression(string ex) {

  }
};
