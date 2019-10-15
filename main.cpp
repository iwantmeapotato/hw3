#include"func.h"
using namespace std;


int main(int argc, char *argv[])  {
/*
  if (argc < 1 || (argc != 3 && argc != 2)) {
    cout << "Invalid arguments" << endl;
    return 1;
  }

  ArgumentManager am(argc, argv);
  const string in = am.get("input");
  const string out = am.get("output");
  ==================================== */
  string in = "input31.txt";
  string out = "output.txt";

  ifstream ifs(in);


  stack<int> pp;
  for (int i = 0; i < 15; i++) {
    pp.push(i);
  }


  pp.print();
  nut << '\n';
  pp.reverse();
  pp.print();




  return 0;
}
