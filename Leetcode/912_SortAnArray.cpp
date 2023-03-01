#include <bits/stdc++.h>
using namespace std;

class SolutionInbuilt {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};

class Solution {
public:

    void merge(int left, int right, vector<int>& arr){
        int mid = left + (right-left)/2;
    int l_aux_size = mid-left+1;
    int r_aux_size = right - mid;
    int* l_aux = new int[l_aux_size];
    int* r_aux = new int[r_aux_size];

    for (int i = 0; i < l_aux_size; i++)
    {
        l_aux[i] = arr[left+i];
    }
    for (int j = 0; j < r_aux_size; j++)
    {
        r_aux[j] = arr[mid+j+1];
    }
    int i=0,j=0,k=left;
    while(i<l_aux_size && j<r_aux_size){
        if (l_aux[i]<=r_aux[j])
        {
            arr[k] = l_aux[i];
            i++;
        }
         else{
        arr[k] = r_aux[j];
        j++;
    }
    k++;
}
    while(i<l_aux_size){
    arr[k] = l_aux[i];
    i++;
    k++;
}
    while(j<r_aux_size){
    arr[k] = r_aux[j];
    j++;
    k++;
    }
    }

    void mergeSort(vector<int>& v, int l, int r){
        if (l>=r){
            return;
        }
        int mid = l + (r-l)/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,r);
        merge(l,r,v);
    }

    vector<int> sortArray(vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;
        mergeSort(nums, low, high);
        return nums;
    }
};