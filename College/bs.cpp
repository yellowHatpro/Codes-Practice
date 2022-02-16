//binary search
#include <bits/stdc++.h>
using namespace std;
//binary search
 void binarysearch(int arr[] , int size , int key){
        int low = 0;
        int high = size - 1;
        int mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(arr[mid] == key){
                cout << "Element found at index " << mid << endl;
                return;
            }
            else if(arr[mid] < key){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << "Element not found" << endl;
 }

int main() 
{ 
    //Linear Search
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int key = 90; 
    int i; 
    bool isFound = false; 
    for (i = 0; i < n; i++) 
    { 
        if (arr[i] == key) 
        { 
            isFound = true; 
            break; 
        } 
    } 
    if (isFound) 
        cout << "Element found at index " << i; 
    else
        cout << "Element not found"; 

        //bineary search
       int arr2[] = {11,12,13,14,15,16,17,18,19,20};
        int size = sizeof(arr)/sizeof(arr[0]);
        int key2 = 15;
        binarysearch(arr2,size,key2);
    return 0; 
}