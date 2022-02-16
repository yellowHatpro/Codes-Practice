#include <bits/stdc++.h>
using namespace std;

void merge(int l , int r , int* arr){
int mid = l + (r-l)/2;
int l_aux_size = mid-l+1;
int r_aux_size = r - mid;
int l_aux[l_aux_size];
int r_aux[r_aux_size];
//filling auxilliary arrays
for(int i=0;i<l_aux_size;i++){
    l_aux[i] = arr[l+i];
}
for (int j = 0; j < r_aux_size; j++)
{
    r_aux[j] = arr[mid+1+j];
}
int i=0,j=0,k=l;
while(i<l_aux_size && j<r_aux_size){
    if(l_aux[i]<=r_aux[j]){
        arr[k] = l_aux[i];
        i++;
    }
    else{
        arr[k] = r_aux[j];
        j++;
    }
    k++;


}
}

void mergeSort(int left, int right , int *arr){
    if(left>right){
        return;
    }
mergeSort(left,(left+right)/2,arr);
mergeSort((left+right)/2+1,right,arr);
merge(left, right,arr);
for (int i = 0; i < right-left; i++)
{
    cout<<arr[i]<<" ";
    cout<<endl;
}
}

int main(){
    int arr[10] = {43,34,22,22,25,2,6,2,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(0 , size-1,arr);
}