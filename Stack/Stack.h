#include <bits/stdc++.h>
using namespace std;

// Dynamic Stack
class Stack {
  int *data;
  int nextIndex;
  int capacity;

public:
  // We can also make a constructor with no args since we dont care about size,
  // but just for fun I am making it in a way that user is conscious about
  // size..
  Stack(int size) {
    data = new int[size];
    nextIndex = 0;
    capacity = size;
  }

  int size() { return nextIndex; }

  bool isEmpty() { return nextIndex == 0; }

  void push(int element) {
    if (nextIndex == capacity) {
      capacity *= 2 int *newArray = new int[capacity];
      for (int i = 0; i < capacity; ++i) {
        newArray[i] = data[i];
      }
      delete[] data;
      data = newArray;
    }
    data[nextIndex++] = element;
  }

  int pop() {
    if (isEmpty()) {
      cout << "Stack Empty" << endl;
      return INT_MIN;
    }
    nextIndex--;
    return data[nextIndex];
  }

  int top() {
    if (isEmpty()) {
      cout << "Stack Empty" << endl;
      return INT_MIN;
    }
    return data[nextIndex - 1];
  }
};
