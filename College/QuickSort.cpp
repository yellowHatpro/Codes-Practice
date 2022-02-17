/* Pseudo Code for Quick Sort
low-> Starting index, high-> Ending index
quickSort(arr[],low,high)
{
    if(low<high){
       //  pi -> partitioning index
       // arr[pi]-> Partitioning element , which is at the correct position
        pi = partition(arr[],low,high);

        quickSort(arr,low,pi-1) // Before pi
        quickSort(arr,pi+1,high) // After pi
        //Remember we dont need to include pi in the recursive calls

       
    }
}
*/
/*
// Pseudo Code for Partition Algorithm
This function takes last element as pivot , places the pivot element at its correct position in sorted array, and places all smaller elements than pivot element to left of pivot and all greater elements to right of pivot
partition(arr[],low,high)
{
    //pivot (Element to be placed at right position)
    pivot = arr[high];
    i = (low-1) // Index of smaller element ,currently -1
    for (j=low , j<=high-1,j++){
        // If current element is smaller than or equal to pivot element
        if(arr[j]<=pivot){
            i++; // increment index of smaller element
            swap(arr[i],arr[j])
        }
    }
    swap(arr[i+1],arr[high])
    return (i+1)
}
*/