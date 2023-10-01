#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5};
  arr.push_back(11);
  cout << "size " << arr.size() << endl;
  cout << "size " << arr.capacity() << endl;

  // remove last element
  arr.pop_back();

  // For each loop
  for (int m : arr) {
    cout << m << " ";
  }
  cout << endl;
  // Fill constructor (size,element)
  vector<int> fillDemoVector(4, 7);
  for (auto m : fillDemoVector) {
    cout << m << " ";
  }
  cout << endl;

  vector<vector<int>> arr2d = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  // For each in 2d
  cout << "Printing vector<vector<int>>" << endl;
  for (vector<int> i : arr2d) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
