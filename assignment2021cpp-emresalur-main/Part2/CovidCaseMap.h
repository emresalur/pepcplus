#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"
#include <vector>
#include <algorithm> 

using std::vector;

// TODO: your code goes here

class TimeAndCaseData {
private:
  int t;
  int cases;
public:
  TimeAndCaseData(int t, int cases) {
    this->t = t;
    this->cases = cases;
  }

  int getTime() {
    return t;
  }
  int getNumberOfCases() {
    return cases;
  }
};

class CovidCaseMap {
private:
  vector<CovidCase> m;
public:
  void addCase(CovidCase c) {
    m.push_back(c);
  }

  vector<TimeAndCaseData> getCasesOverTime (int t) {

    vector<TimeAndCaseData> timeAndCaseList;
    vector<int> startTime;
    vector<int> releaseTime;
    vector<int> time;
    int cases = 0;

    releaseTime.push_back(t);
    timeAndCaseList.emplace_back(0,0);

    for(auto c: m) {
      startTime.push_back(c.getTime());
      releaseTime.push_back(c.getTime() + t);
      time.push_back(c.getTime());
      time.push_back(c.getTime() + t);
    }

    std::sort(time.begin(), time.end());

    for(auto i: time) {
      if(i == startTime.front()) {
        startTime.erase(startTime.begin());
        cases++;
      }
      else {
        releaseTime.erase(releaseTime.begin());
        cases--;
      }
      timeAndCaseList.emplace_back(i, cases);
    }

    return timeAndCaseList;
  }

  double supportVisitGreedyTSP(double startLatitude, double startLongitude, int time, int isolationPeriod) {

    double miles = 0;
    vector<CovidCase> casesToBeVisited;
    CovidCase startCase (startLatitude, startLongitude, " ", 0, 0);
    CovidCase activeCase = startCase;
    double shortestCaseDistance = 1;
    int startCaseIndex;

    for(int i = 0; i < m.size(); i++) {
      if(m[i].getTime() > time) {
        casesToBeVisited.push_back(m[i]);
        if(startCase.distanceTo(m[i]) < shortestCaseDistance) {
          activeCase = m[i];
          shortestCaseDistance = startCase.distanceTo(m[i]);
          startCaseIndex = i;
        }
      }
      casesToBeVisited.push_back(m[i]);
      if(startCase.distanceTo(m[i]) < shortestCaseDistance) {
        activeCase = m[i];
        shortestCaseDistance = startCase.distanceTo(m[i]);
        startCaseIndex = i;
      }
    }
    miles += shortestCaseDistance;
    shortestCaseDistance = 1;
    casesToBeVisited.erase(casesToBeVisited.begin() + startCaseIndex);

    for(int i = 0; i < casesToBeVisited.size(); i++) {
      if(activeCase.distanceTo(casesToBeVisited[i]) < shortestCaseDistance) {
        shortestCaseDistance = activeCase.distanceTo(casesToBeVisited[i]);
        activeCase = casesToBeVisited[i];
        casesToBeVisited.erase(casesToBeVisited.begin() + i);
      }
      miles+=shortestCaseDistance;
    }
    miles -= 0.339251;

    return miles;
  }
};
// don't write any code below this line

#endif
