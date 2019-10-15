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


  string expr;
  while (!ifs.eof()) {
    getline(ifs, expr);
    expression function(expr);
    nut << function.evaluate() << '\n';
  }

  // stack<long long int> pp;


  /*
  0*00000000000000000+0000000000000001=1
  -(-(-1))+3=2
  (-1*(3+5))=-8
  */



  return 0;
}
