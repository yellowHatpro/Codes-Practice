--+#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


void insertionSort(int size, int *arr){
	int key ;
	for (int i = 1; i < size; ++i)
	{
		key = arr[i]; //We will check if any element is larger than this key,
		int j=i-1; // and we will start checking in backward direction, starting from element just before the key element, that's why we start outer for loop with i=1
		while(j>=0 && arr[j]>key){//if the current value is greater than the key,
			arr[j+1] = arr[j]; // shift the value right 
			j--;
		}
		arr[j+1] = key;
	}
}

void merge(int left,int right, int* arr){
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

void mergeSort(int left, int right, int* arr){
if (left>=right){
	return;
}
int mid = left +(right-left)/2;
mergeSort(left,mid,arr);
mergeSort(mid+1,right,arr);
merge(left,right,arr);
}

void insertion4000(){
	//1. When array is of size 40
	int arr40[4001] = {};
	for (int i = 0; i < 4000; ++i)
	{
		arr40[i] =1+ (rand()%8000);
	}
	auto start = steady_clock::now();
	insertionSort(4000,arr40);
	auto stop = steady_clock::now();
	for (int i = 0; i < 4000; ++i)
	{
		cout<<arr40[i]<<" "; 
	}
	cout<<endl;
	  
	cout<<"the running time of insertionSort is (in ms) : "<<duration_cast<microseconds>(stop-start).count()<<endl;
}

mergeTime(){
	int arr40[4001] = {};
	
	for (int i = 0; i < 4000; ++i)
	{
		arr40[i] =1+ (rand()%8000);
	}
	auto start = steady_clock::now();
	mergeSort(0,3999,arr40);
	auto stop = steady_clock::now();
	for (int i = 0; i < 4000; ++i)
	{
		cout<<arr40[i]<<" "; 
	}
	cout<<endl;
	  
	cout<<"the running time of mergeSort is (in ms) : "<<duration_cast<microseconds>(stop-start).count()<<endl;
}

bool linearSearch(int *arr,int size, int key){
	for (int i = 0; i < size; ++i)
	{
		if (arr[i]==key)
		{
			return true;
		}
	}
	return false;
}

bool binarySearch(int low, int  high, int *arr, int key){
	while(low<=high)
}

int main(){
	//insertion4000();
	//mergeTime();
	int arr40[4001] = {};
	
	for (int i = 0; i < 4000; ++i)
	{
		arr40[i] =1+ (rand()%8000);
	}
	auto start = steady_clock::now();
	mergeSort(0,3999,arr40);

}

