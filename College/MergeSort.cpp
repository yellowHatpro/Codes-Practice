/*
MergeSort(arr[],l,r)
If r>l
    1. Find the middle point to divide the array into two halves :
        middle m=(l+r)/2
    2. Call mergeSort for first half :
        Call mergeSort(arr, l, m)
    3. Call mergeSort for second half:
        Call mergeSort(arr,m+1,r)
    4. Merge the two halves sorted in step 2 and 3:
        Call merge(arr,l,m,r)
*/

#include <iostream>
using namespace std;

void merge(int l , int r , int* arr){
int mid = l + (r-l)/2;
int l_aux_size = mid-l+1;
int r_aux_size = r - mid;
int* l_aux = new int[l_aux_size];
int* r_aux = new int[r_aux_size];
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

void mergeSort(int left, int right , int *arr){
    if(left>=right){
        return;
    }
    int mid = left + (right-left)/2;
mergeSort(left,mid,arr);
mergeSort(mid+1,right,arr);
merge(left, right,arr);
}

int main(){
    int arr[10] = {43,34,22,22,25,2,6,2,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(0 , size-1,arr);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}