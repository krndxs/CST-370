/* Title: hw9_2.cpp
* Abstract :Write a C++ (or Java) program named hw9_2.cpp (or hw9_2.java) that displays the performance of merge sorting and quick sorting algorithms on the screen. .
* Link to source code: https://www.geeksforgeeks.org/cpp-program-for-quicksort/, https://www.geeksforgeeks.org/merge-sort/, https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
* Author: Karandeep Singh
* ID: 2004
* Date: 4/20/2021
*/

#include <queue>
#include<iostream>
#include <list>
#include <time.h>
#include <chrono>
#include <limits.h>

using namespace std;
using namespace std::chrono;


//QUICK SORT

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
          at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions


//MERGE SORT

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

 
// Driver code

int main(){

    int v1;
    cout << "Enter input size: ";
    cin >>  v1;
    int *ran_array = new int [v1];
    int *ran_array_copy = new int [v1];
    srand(time(NULL));   
    for(int i = 0; i < v1; i++){
      
        ran_array[i] = rand() % INT_MAX;
    }
    
    for(int i = 0; i < v1; i++){
        ran_array_copy[i] = ran_array[i];
    }
    
   auto start = high_resolution_clock::now();
  
    // Call the function, here sort()
    quickSort(ran_array, 0, v1);
  
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
  
  
    cout << "===================== Execution Time ====================\n"
         "Quick sort:   " << duration<double>(stop - start).count() << " millisecond" << endl;
         
         
    start = high_resolution_clock::now();
  
    // Call the function, here sort()
    mergeSort(ran_array_copy, 0, v1);
  
    // Get ending timepoint
    stop = high_resolution_clock::now();
  
  
    cout << "Merge sort:   " << duration<double>(stop - start).count() << " millisecond" << endl;
    cout << "=========================================================";
    

}

 
