

  /*
  int function(string expr) { //numerical evaluation
    cout << "\n\nNEW FUNCTION: " << expr << "\n\n";
    stack<long long int> numbers;
    stack<char> operators;
    istringstream ss(expr);
    int tmp_i; char tmp_c;

    //simplify into stacks
    while (!ss.eof()) {
      if (ss.peek() >= '0' && ss.peek() <= '9') { //is a number
        ss >> tmp_i;
        numbers.push(tmp_i);
      }

      else {  //is an operator
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
        operators.push(tmp_c);
      }

      // cout << string(3, '\n');
    }
    //eval stacks

    return numbers.top->data;
  }
  */

  // while(!operators.empty()) {
    // op = operators.pop();

    // cAlcUlaTe
  // }


  // simplify(s_exp);
  /*
  function(s_exp);
  int result;
  try {
    result = function(s_exp);
  }
  catch(...) { return "error"; }
  return original + "=" + to_string(result);
  */


/*
  int function(string expr) { //numerical evaluation
    stack<char> operators;
    stack<string> post_exp;
    istringstream ss(expr);
    long long int tmp_i; char tmp_c, s_top;

    //create postfix
    while (!ss.eof()) {
      if (ss.peek() >= '0' && ss.peek() <= '9') { //is a number
        ss >> tmp_i;
        post_exp.push(to_string(tmp_i), 0);
      }

      else {  ///is an operator
        ss >> tmp_c; if (ss.eof()) break; //don't know why but this is needed
        if (operators.empty() || tmp_c == '(') operators.push(tmp_c);
        else if (tmp_c == ')') {  //if close parens
          while (operators.top->data != '(') {  //pop until find the open
            post_exp.push(string(1, operators.pop()));
          }
          operators.pop();
        }
        else {  ///functional operators
          s_top = operators.top->data;
          while(!operators.empty() && priority(tmp_c) <= priority(s_top)) {
            s_top = operators.pop();
            post_exp.push(string(1, s_top));
            if (!operators.empty()) s_top = operators.top->data;
          } //sure to reset top->data so while() condition can compare the popped op with the correct next one
          operators.push(tmp_c);
        }
      }
    }
    while(!operators.empty()) post_exp.push(string(1,operators.pop())); //out of #s, dump the rest
    // eval postfix

    //if adjacent ()() then *


    // cout << string(, '\n');
    // cout << "\npostfix: \n";
    // post_exp.rprint();


    return 0;
  }

*/
