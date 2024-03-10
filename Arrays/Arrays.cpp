#include <iostream>
using namespace std;

void dyn_arr() {
     int* arr = new int[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < 100; i++)
    {
        cout<<arr[i]<<endl;
    }
    delete[] arr;
}

void multidimension_array() {
    int** arr2d = new int*[5];
    for(int i = 0; i < 5; i++){
        arr2d[i] = new int[5];
        for(int j = 0; j < 5; j++){
            arr2d[i][j] = i*j;
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j=0; j<5; j++){
            cout<<arr2d[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(int argc, char const *argv[])
{
    multidimension_array();
    return 0;
}
