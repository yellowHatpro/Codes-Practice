#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int *arr, int size){
int min_index;
for(int i=0;i<size-1;i++){
    min_index=i;
    for(int j=i+1;j<size;j++){
        if(arr[j]<arr[min_index]){
            min_index=j;
        }
        swap(&arr[i],&arr[min_index]);

    }
}
for (int i = 0; i < size; i++)
{
    cout<<arr[i]<<" ";
    cout<<endl;
}

}


int main(){
int arr[10] = {43,34,22,22,25,2,6,2,5,4};
int size = sizeof(arr)/sizeof(arr[0]);
selectionSort(arr,size);
}