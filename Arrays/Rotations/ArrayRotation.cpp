#include <bits/stdc++.h>
using namespace std;
// Rotation
// 1. rotate(arr[],d,n) d-elements rotate in arr[] of size n
// 1 2 3 4 5 6 7 , d=2 -> 3 4 5 6 7 1 2

// METHOD 1 Using Temp array
// TC On , Aux O(d)
/*
Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
1) Store the first d elements in a temp array
   temp[] = [1, 2]
2) Shift rest of the arr[]
   arr[] = [3, 4, 5, 6, 7, 6, 7]
3) Store back the d elements
   arr[] = [3, 4, 5, 6, 7, 1, 2]
*/

//-------------------------------------------------------------

// METHOD 2 Rotate one by one
/*
leftRotate(arr[], d, n)
start
  For i = 0 to i < d
    Left rotate all elements of arr[] by one
end

TC O(n*d)
Aux O(1)
*/

void leftRotateByOne(vector<int> v, int n) {
    int temp = v[0];
    for (int i = 0; i < n - 1; i++)
        v[i] = v[i + 1];  // left rotate element by 1
    v[n - 1] = temp;
}

void leftRotate(const vector<int>& v, int n, int d) {
    for (int i = 0; i < d; ++i) {
        leftRotateByOne(v, n);
    }
}

//-------------------------------------

// Method 3- Juggling Algorithm
/*
Extension of method 2-> Divide array into different sets
Number of sets -> gcd(n,d)
TC O(n)
Aux O(1)
*/
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else {
        return gcd(b, a % b);
    }
}

void leftRotateOptimized(vector<int> v, int d, int n) {
    // In case d>=n
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; ++i) {
        // move i-th values of blocks
        int temp =v[i];   // element in the first set that is to be placed in last set
        int j = i;  // iterator for inner loop inside the sets
        while (true) {
            int k = (j + d) % n;  // number of steps to be shifted each time
            if (k == i) break;
            v[j] = v[k];
            j = k;
        }
        v[j] = temp;
    }
}

// -------------------------------------------------------------
// METHOD -4- Using Reversal Algorithm- Best, Use this only
/*rotate(arr[], d, n)
  reverse(arr[], 1, d) ;
  reverse(arr[], d + 1, n);
  reverse(arr[], 1, n);

  TC O(n)
  Aux O(1)
*/
void reverseArray(vector<int> v, int start, int end) {
    while (start < end) {
        swap(v[start], v[end]);
        start++;
        end--;
    }
}
//1 2 3 4 5 d=2 -> 3 4 5 1 2
void leftClockWiseRotate(const vector<int>& v, int d, int n) {
    if (d == 0) return;
    d = d % n;  // In case d>=n
    reverseArray(v, 0, d - 1);
    reverseArray(v, d, n - 1);
    reverseArray(v, 0, n - 1);
}


//1 2 3 4 5, d=2 ->  4 5 1 2 3
void rightClockWiseRotate( vector<int>& v, int d, int n) {
    if (d == 0) return;
    d = d % n;  // In case d>=n
    reverseArray(v, 0, n - 1);
    reverseArray(v, 0, d - 1);
    reverseArray(v, d, n - 1);
}

// -------------------------------------------------------------
// CYCLIC ROTATIONS
// -------------------------------------------------------------
/* Program to cyclically rotate an array by one
Given an array, cyclically rotate the array clockwise by one.
For example, if the array is {1, 2, 3, 4, 5}, it should become {2, 3, 4, 5, 1}.

METHOD-1: rotateClockwise
TC O(n)
*/

void rotateClockwise(vector<int> &v, int n) {
    int temp = v[n - 1];
    for (int i = n - 1; i > 0; i--) v[i] = v[i - 1];
    v[0] = temp;
}

// METHOD-2: two pointer
void rotateClockwiseTwoPointer(vector<int> &v, int n) {
    int i = 0, j = n - 1;
    while (i != j) {
        swap(v[i], v[j]);
        i++;
    }
}

// UTILITY FUNCTIONS
void printArray(const vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;
    int n = v.size();
    cout << "Before rotation: ";
    printArray(v);
    cout<< "After rotation: ";
    leftRotate(v, n, d);
    printArray(v);
    return 0;
}