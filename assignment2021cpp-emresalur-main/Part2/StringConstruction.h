#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <string>
#include <vector>
using std::string;
using std::vector;

// TODO: your code goes here:
int stringConstruction(string target, int cloneCost, int appendCost)
{
    vector<string> stringList;
    string cloneString;
    int index = 0;
    int totalCost = 0;
    int totalAppendCost = 0;

    while(index < target.size()) {
      string currentString = "";
      for(int i = 0; i < stringList.size(); i++) {
        string targetSubstring = target.substr(index, stringList[i].length());
        if(targetSubstring == stringList[i]) {
          currentString = stringList[i];
        }
      }
      if(currentString.size() == 0) {
        currentString = target.substr(index, 1);
      }
      totalAppendCost = appendCost * currentString.length();
      if(totalAppendCost > cloneCost) {
        totalCost += cloneCost;
        cloneString += currentString;
        index += currentString.length();
      }
      else{
        totalCost += appendCost * currentString.length();
        for(int i = 0; i < currentString.length(); i++) {
          cloneString += currentString.substr(i, 1);
          index++;
        }
      }
      stringList.push_back(cloneString);
    }
    return totalCost;
}
// do not write or edit anything below this line

#endif
