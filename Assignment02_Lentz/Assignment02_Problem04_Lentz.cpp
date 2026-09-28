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
// Problem 4: Quick Sort
//===============================================================

// Function 1: prints the n elements of arr on one line, separated by spaces
void printArray(const int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// partition helper function
int partition(int arr[], int low, int high, int& comparisons, bool firstPartition){
    int pivot = arr[high];
    int i = low-1;

    for (int j=low; j<= high-1; j++){
        comparisons += 1;

        if (arr[j] <= pivot){
            i = i+1;
            swap(arr[i], arr[j]);

            // output only for the first partition
            if (firstPartition) {
                cout << "i = " << i << ", j = " << j << ": ";
                printArray(arr + low, high - low + 1); 
            }
        }
    }

    swap(arr[i+1], arr[high]); 


    // print final pivot swap for first partition
    if (firstPartition) {
        cout << "i = " << i + 1 << ", j = " << high << ": ";
        printArray(arr + low, high - low + 1); 
        cout << "Pivot " << pivot
             << " final position: " << i + 1 << endl;
    }

    return i+1;
}

// Function 2: sorts arr in increasing order (the name changes per problem)
void quickSort(int arr[], int low, int high, int& comparisons, int depth = 0){
    if (low < high){
        // identify the first partition
        bool firstPartition = (depth == 0);

        // print pivot and subarray for this recursive call
        cout << string(depth, ' ') << "Pivot: " << arr[high] << ", subarray: ";
        printArray(arr + low, high - low + 1);

        int p = partition(arr, low, high, comparisons, firstPartition); 

        // sort left side
        quickSort(arr, low, p-1, comparisons , depth + 1);

        // sort right side
        quickSort(arr, p+1, high, comparisons, depth + 1);
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

    // counters for comparisons and swaps
    int comparisons = 0;

    // Original array
    cout << "Original: ";
    printArray(A, n);

    // call the sorting function
    quickSort(A, 0, n - 1, comparisons);

    cout << "Sorted: ";
    printArray(A, n); // print the sorted array

    // print number of comparisons and swaps
    cout << "Total comparisons: " << comparisons << endl;
}
