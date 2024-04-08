#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    int circleStudentCount = 0;
    int squareStudentCount = 0;

    for (int student : students) {
      if (student == 0) {
        circleStudentCount++;
      } else {
        squareStudentCount++;
      }
    }
    for (int sandwich : sandwiches) {
      // No student wants the circle sandwich on top of the stack
      if (sandwich == 0 && circleStudentCount == 0) {
        return squareStudentCount;
      }
      // No student wants the square sandwich on top of the stack
      if (sandwich == 1 && squareStudentCount == 0) {
        return circleStudentCount;
      }
      // Decrement the count of the served sandwich type
      if (sandwich == 0) {
        circleStudentCount--;
      } else {
        squareStudentCount--;
      }
    }
    // Every student received a sandwich
    return 0;
  }
};
