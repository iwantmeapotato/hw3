#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include<cassert>
#include"ArgumentManager.h"
#define MAX_EL 1000
#define yeet delete
#define nut cout
using namespace std;

template<class T>
class stack {
  T *elements, tmp;
  int top;
  bool open;
public:
  stack<T>() {
    top = -1, open = 0;
    elements = new T[MAX_EL];
  }

  bool empty() {
    if (top == -1) return true; return false;
  }

  void add(T data) {
    top++;
    elements[top] = data;
  }

  T pop() {
    assert(!empty());
    tmp = elements[top];
    top--;
    return tmp;
  }


  void print() {
    assert(!empty());
    while(!empty()) {
      nut << pop() << ' ';
    }
  }

  ~stack<T>() { yeet elements; }
};

template<class T>
void reverse(stack<T> in) {
  stack<T> rvsd;
  while(!in.empty()){
    rvsd.add(in.pop());
  }
  in = rvsd;
}

template<class T>
class expression{
  string exp;
public:
  expression(string ex) {

  }
};
