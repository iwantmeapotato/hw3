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
  /*
  while (!ifs.eof()) {
    getline(ifs, expr);
    expression function(expr);
    nut << function.evaluate() << '\n';
  }
  */


  expr = "(1+2)*(1000+2000)";
  expression function(expr);
  nut << function.evaluate() << '\n';



  /*
  0*00000000000000000+0000000000000001=1
  (1+2)*(1000+2000)=9000
  (+1+2)*(1000+2000)=9000
  -(-(-1))+3=2
  (-1*(3+5))=-8

  ((1+2)*(1000+2000))*(1+10000)=90009000 <----

  */



  return 0;
}
