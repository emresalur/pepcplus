// TODO: Replace this file with your CovidCase.h from Part1
// then extend as per the instructions in README.md

// TODO: Replace this file with your CovidCase.h from Part1
// then extend as per the instructions in README.md

#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <cmath>
#include <iostream>
using std::ostream;
using std::string;

// TODO: your code  goes here

class CovidCase {
private:
  double latitude;
  double longitude;
  string name;
  int age;
  int time;
public:
  CovidCase (double latitude, double longitude, string name, int age, int time) {
    this->latitude = latitude;
    this->longitude = longitude;
    this->name = name;
    this->age = age;
    this->time = time;
  }
  CovidCase (string s) {

    int pos = 0;

    for(int i = pos; i < s.length(); i++) {
      if(s.at(i) == ',') {
        this->latitude = std::stod(s.substr(pos, i - pos));
        pos = i+1;
        break;
      }
    }
    for(int i = pos; i < s.length(); i++) {
      if(s.at(i) == ',') {
        this->longitude = std::stod(s.substr(pos, i - pos));
        pos = i + 3;
        break;
      }
    }
    for(int i = pos; i < s.length(); i++) {
      if(s.at(i) == ',') {
        this->name = s.substr(pos, i - (pos+1));
        std::cout << this->name << '\n';
        pos = i + 1;
        break;
      }
    }
    for(int i = pos; i < s.length(); i++) {
      if(s.at(i) == ',') {
        this->age = std::stoi(s.substr(pos, i - pos));
        pos = i + 1;
        break;
      }
    }
    for(int i = pos; i < s.length(); i++) {
      this->time = std::stoi(s.substr(pos, s.length() - pos));
    }

  }

  friend ostream& operator<<(ostream& o, const CovidCase& c) {
    o<< '{' << c.latitude<<", "<<c.longitude<<", \"" <<c.name<<"\", "<<c.age<<", "<<c.time << '}';
    return o;
  }

  double convert(double degree) {
    return (degree * (M_PI / 180));
  }

  double distanceTo(CovidCase cas) {
    double dlon = cas.longitude - longitude;
    double dlat = cas.latitude - latitude;
    double a = pow((sin(convert(dlat)/2)), 2) + cos(convert(longitude)) * cos(convert(cas.longitude)) * pow((sin(convert(dlon))/2), 2);
    double c = 2 * atan2( sqrt(a), sqrt(1-a));
    int r = 3960;
    double distance = r * c;
    return distance;
  }

  bool operator==(const CovidCase c1) const{
    if(c1.latitude == latitude && c1.longitude == longitude && c1.name == name && c1.age == age && c1.time == time){
      return true;
    }
    else {
      return false;
    }
  }

  double getLatitude() {
    return latitude;
  }

  double getLongitude() {
    return longitude;
  }

  string getName() {
    return name;
  }

  int getAge() {
    return age;
  }

  int getTime() {
    return time;
  }

};
// don't write any code below this line

#endif
