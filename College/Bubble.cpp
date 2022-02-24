//Bubble Sort
//Brute Force Approach
//Time Complexity : O(n^2)
//In Bubble Sort, we compare adjacent elements and swap them if they are in wrong order.
//We keep repeating this process until the array is sorted.
//Array sorts starting from right.
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void bubbleSort(int arr[], int n) 
{ 
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) 
                swap(&arr[j], &arr[j+1]); // In each iteration larger element shifts to right of the array
    }
            }
    }

int main() 
{ 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
}    