#include <bits/stdc++.h>
using namespace std;

class Student {
public:
  string name;
  int classs;

  Student() { cout << "constructor called" << endl; }
};

int main() {

  // Dynamically created object
  Student *ashu = new Student;
  (*ashu).name = "ashu"; // both same
  ashu->name = "ashu";   // 2 ways for dynamic objects

  // Statically created object
  Student ashutosh;
  ashutosh.name = "ashutosh";

  cout << ashu->name << endl;
  cout << (*ashu).name << endl;
  cout << ashutosh.name << endl;

  Student s1;
  Student s2(s1); // Copy Constructor, s2 me s1 ki values copied
  Student s3;
  Student s4;
  s3 = s4; // = here is Copy Assign Operator, copies values from s4 to s3
  Student s6 = s4; // Here internally copy constructor is used

  return 0;
}
