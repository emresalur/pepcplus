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
  int positive;
public:
  CovidCase (double latitude, double longitude, string name, int age, int positive) {
    this->latitude = latitude;
    this->longitude = longitude;
    this->name = name;
    this->age = age;
    this->positive = positive;
  }

  friend ostream& operator<<(ostream& o, const CovidCase& c) {
    o<< '{' << c.latitude<<", "<<c.longitude<<", \"" <<c.name<<"\", "<<c.age<<", "<<c.positive << '}';
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
};
// don't write any code below this line

#endif
