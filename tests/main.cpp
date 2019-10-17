#include"func.h"
using namespace std;

int main(int argc, char *argv[])  {
  if (argc < 1 || (argc != 3 && argc != 2)) {
    yell << "Invalid arguments" << endl;
    return 1;
  }
  ArgumentManager am(argc, argv);
  const string in = am.get("input");
  const string out = am.get("output");
  ifstream ifs(in);
  ofstream ofs(out);

  string expr;
  if (ifs.peek() == -1) { ofs << "error"; yell << "error"; }
  while (!ifs.eof()) {
    getline(ifs, expr);
    if (expr == "") { continue; }
    expression function(expr);
    if (!function.valid) { ofs << "error\n"; yell << "error\n"; continue; }
    ofs << function.print() << '\n';
  }

  ofs.close();

  return 0;
}
