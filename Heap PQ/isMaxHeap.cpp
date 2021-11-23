bool isMaxHeap(int arr[], int n) {
    if (n==1)
    {
        return true;
    }
    for (int i = 1; i < n; i++)
    {
        int pi = (i-1)/2;
        if(arr[pi]<arr[i]){
            
            return false;
        }
    }
    return true;
}