#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <map>
#include <limits>
using namespace std;

//Every program must have (1) a function printArray that prints the array,
//and (2) a function that sorts it. Whenever a problem asks you to print the array, call printArray;
//do not write printing loops inside the sorting function or main().

//===============================================================
// Problem 5: Merge Sort
//===============================================================


// Function 1: prints the n elements of arr on one line, separated by spaces
void printArray(const int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//helper function merge
void merge(int arr[], int low, int mid, int high, int &comparisons, int &lastMergeComparisons){ 
    vector<int> L(arr + low, arr + mid + 1);  // left array
    vector<int> R(arr + mid + 1, arr + high + 1); // right array
    int i = 0;
    int j = 0;
    int k = low;
    int count = 0; // comparison counter
    while (i < L.size() and j < R.size()){ 
        count+=1; // add a comparison
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i+=1;
        }

        else{
            arr[k] = R[j]; 
            j+=1;
        }

        k+=1;
    } 

    // while i aka left pointer is less than the size of the left array
    while (i<L.size()){ 
        arr[k] = L[i];
        i+=1;
        k+=1;
    }

    // while j aka right pointer is less than the size of the right array
    while (j<R.size()){ 
        arr[k] = R[j];
        j+=1;
        k+=1;
    }

    comparisons += count;  // total comparisons
    lastMergeComparisons = count;  // last  merge comparisons
}


// Function 2: sorts arr in increasing order (the name changes per problem)
void mergeSort(int arr[], int low, int high, int &comparisons, int &lastMergeComparisons){ 
    if (low<high){
        int mid = (low+high)/2;

        cout << "Split: "; //label split output
        printArray(arr + low, high - low + 1); //print the subarray that is about to be split

        mergeSort(arr, low, mid, comparisons, lastMergeComparisons); // sort left side of array
        mergeSort(arr, mid+1, high, comparisons, lastMergeComparisons); // sort right side of array 
        merge(arr, low, mid, high, comparisons, lastMergeComparisons); // merge arrays together in sorted order 

        cout << "Merged: ";  
        printArray(arr + low, high - low + 1); 
    }

}


// Main function
int main() {
    // The given array and its size
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};

    // the sorted array for the check 
    //int A[] = {5, 7, 14, 19, 23, 32, 34, 62};

    //descending order
    //int A[] = {62, 34, 32, 23, 19, 14, 7, 5};  

    int n = sizeof(A) / sizeof(A[0]);

    // comparisons
    int comparisons = 0;
    int finalMergeComparisons = 0;

    // Original array
    cout << "Original: ";
    printArray(A, n);

    // call the sorting function
    mergeSort(A, 0, n - 1, comparisons, finalMergeComparisons);
    cout << "Sorted: ";
    printArray(A, n); // print the sorted array

    // print number of comparisons and comparisons in the final merge 
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Comparisons in final merge: " << finalMergeComparisons << endl;
}


