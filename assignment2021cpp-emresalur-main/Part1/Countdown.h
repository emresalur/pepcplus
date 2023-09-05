#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using std::vector;

// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {

private:
    std::string solution;
    int value;

public:

    CountdownSolution() : solution(), value(0) {}

    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }

    const std::string & getSolution() const {
        return solution;
    }

    int getValue() const {
        return value;
    }

};

// Do not edit above this line

// TODO: write code here:

double evaluateCountdown(std::string str) {
  vector<std::string> tokens;
  vector<double> v;
  double a;
  double b;
  int pos = 0;

  for(int i = 0; i < str.length(); i++) {
    if(str.at(i) == ' ') {
      tokens.push_back(str.substr(pos, i - pos));
      pos = i+1;
    }
  }
  tokens.push_back(str.substr(pos, str.length() - pos));

  for(int i = 0; i < tokens.size(); i++) {
    if(tokens[i] == "+") {
      a = v.back();
      v.pop_back();
      b = v.back();
      v.pop_back();
      v.push_back(b + a);
    }

    else if(tokens[i] == "-") {
     a = v.back();
     v.pop_back();
     b = v.back();
     v.pop_back();
     v.push_back(b - a);
   }
   else if(tokens[i] == "*") {
     a = v.back();
     v.pop_back();
     b = v.back();
     v.pop_back();
     v.push_back(b * a);
   }
   else if(tokens[i] == "/") {
     a = v.back();
     v.pop_back();
     b = v.back();
     v.pop_back();
     v.push_back(b / a);
   }

   else {
     v.push_back(stod(tokens[i]));
   }
   a = 0;
   b = 0;
  }
  return v.back();
}

CountdownSolution solveCountdownProblem(vector<int> v, int target) {

  std::string expression = ""

  for(int i = 0; i < v.length(); i++) {


  }

}

// Do not edit below this line


#endif
