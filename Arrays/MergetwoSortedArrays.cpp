#include <iostream>
using namespace std;
void mergeArrays(int arr1[], int arr2[], int n1 , int n2 , int arr3[]){
    //start iterators
    int i=0;
    int j=0;
    int k=0;
    //start till the smaller array is completely traversed
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3[k] = arr1[i];
            i++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    //store remaining elements of first array , continuing from i ,if it wasn't finished
    while(i<n1){
        arr3[k] = arr1[i];
        i++;
        k++;
    }  
    //store remaining elements of second array , continuing from j ,if it wasn't finished
    while(j<n2){
        arr3[k] = arr2[j];
        j++;
        k++;
    } 
}

int main(){
    int arr1[] = {1,3,5,7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {2,4,6,8};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[n1+n2];
    mergeArrays(arr1,arr2,n1,n2,arr3);

    cout<<"Merged array is : ";
    for(int i=0;i<n1+n2;i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    return 0;
}