#include <bits/stdc++.h>
using namespace std;

// These Array algorithms use the concept of binary search.

// CLASS FIND ELEMENT IN SORTED ROTATED ARRAY
class FindElementinSortedRotatedArray {
   public:
    /*
    Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
             key = 3
    Output : Found at index 8

    Approach:
    1) Find middle point mid = (l + h)/2
    2) If key is present at middle point, return mid.
    3) Else If arr[l..mid] is sorted
        a) If key to be searched lies in range from arr[l]
           to arr[mid], recur for arr[l..mid].
        b) Else recur for arr[mid+1..h]
    4) Else (arr[mid+1..h] must be sorted)
        a) If key to be searched lies in range from arr[mid+1]
           to arr[h], recur for arr[mid+1..h].
        b) Else recur for arr[l..mid]

    TC : O(log n)
    Aux : O(1)

    */
    int findElementInSortedRotatedArray(vector<int> v, int low, int high,
                                        int key) {
        if (high < low) return -1;
        int mid = (low + high) / 2;
        if (v[mid] == key) return mid;

        // If left subarray is sorted
        if (v[low] <= v[mid]) {
            if (key >= v[low] && key <= v[mid])
                return findElementInSortedRotatedArray(
                    v, low, mid - 1,
                    key);  // search in left subarray that is make high as mid-1
            else
                return findElementInSortedRotatedArray(
                    v, mid + 1, high,
                    key);  // search in right subarray that is make low as mid+1
        }
        // If right subarray is sorted
        else {
            if (key >= v[mid] && key <= v[high])
                return findElementInSortedRotatedArray(
                    v, mid + 1, high,
                    key);  // search in right subarray that is make low as mid+1
            else
                return findElementInSortedRotatedArray(
                    v, low, mid - 1,
                    key);  // search in left subarray that is make high as mid-1
        }
    }
};

class PairWithaGivenSumInSortedRotatedArray {
   public:
    /*
     1. Find pivot element: Its the largest element, and adjacent to it is smallest element. Ex: {6,7,8,9,1,2,3,4}
     2. Since we have the two pointers, and array is sorted, we can find 2Sum.
     If the sum is greater than the sum of those two elements,
     shift the right pointer to decrease the value of required sum and if the sum is lesser than the required value,
     shift the left pointer to increase the value of the required sum.
     */
    pair<int,int> indices;
    vector<pair<int,int>> totalPairs;
    int totalPairCount=0;
    //FIRST FUNCTION
    bool pairInSortedRotated(vector<int> v, int n, int x) {
        // Find Pivot Element
        int pivot = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] > v[i + 1]) {
                pivot = i;
                break;
            }
        }
        int l = (pivot+1)%n;// l is the smallest element index
        int r = pivot; // r is the largest element index
        while(l!=r){
            if(v[l]+v[r]==x){
                //ELEMENTS ARE FOUND
                indices.first = l;
                indices.second = r;
                return true;
            }
            else if(v[l]+v[r]<x){
                l=(l+1)%n; // shift l to the right by 1 in circular fashion
            }
            else{
                r=(n+r-1)%n;//Shift r to the left in a circular fashion
            }
        }
        return false;
        
    }

    //SECOND FUNCTION
    int pairsInSortedRotated(vector<int> v, int n, int x){
        int pivot=0;
        for (int i = 0; i < n-1; ++i) {
            if (v[i] > v[i + 1]) {
                pivot = i;
                break;
            }
        }
        int l = (pivot+1)%n;// l is the smallest element index
        int r =pivot;
        while(l!=r){
            if(v[l]+v[r]==x){
                totalPairCount++;
                totalPairs.emplace_back(l,r);
                if (l==(r-1+n)%n) return totalPairCount;// if l and r are adjacent, then break
                l=(l+1)%n; // shift l to the right by 1 in circular fashion
                r=(n+r-1)%n;//Shift r to the left in a circular fashion
            }
            else if(v[l]+v[r]<x){
                l=(l+1)%n; // shift l to the right by 1 in circular fashion
            }
            else{
                r=(n+r-1)%n;//Shift r to the left in a circular fashion
            }
        }
        return totalPairCount;
    }
};

int main() {
    vector<int> v = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    int n = v.size();
    FindElementinSortedRotatedArray f;
    int index = f.findElementInSortedRotatedArray(v, 0, n - 1, key);
    cout << "Element found at index " << index << endl;
    int sum = 10;
    PairWithaGivenSumInSortedRotatedArray p;
    bool res = p.pairInSortedRotated(v, n, sum);
    cout << "Pair with given sum " << sum << " is bool: "<<res<<": {" << p.indices.first<<","<<p.indices.second<<"}" << endl;
    // NEXT VECTOR
    vector<int> v2 = {10,11,12,13,14,1,2,3,4,5};
    int n2 = v2.size();
    int sum2 = 15;
    int res2 = p.pairsInSortedRotated(v2, n2, sum2);
    cout << "Total pairs with given sum " << sum2 << " are " << res2 << endl;
    for (auto & totalPair : p.totalPairs) {
        cout << "{" << totalPair.first << "," << totalPair.second << "}" << endl;
    }
    return 0;
}