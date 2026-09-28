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
// Problem 3: Selection Sort
//===============================================================


// Function 1: prints the n elements of arr on one line, separated by spaces
void printArray(const int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


// Function 2: sorts arr in increasing order (the name changes per problem)
void selectionSort(int arr[], int n, int& comparisons, int& swaps){    
    // set up comparisons and swaps
    comparisons = 0;
    swaps = 0;
    
    // for i from 0 to n-1:
    for (int i = 0; i<=n-2; i++){
        // minIdx = i
        int minIdx = i;

        // for j from i+1 to n-1:
        for (int j = i+1; j <= n-1; j++){
            // add a count to comparisons
            comparisons+=1;
            // if arr[j] < arr[minIdx]:
            if (arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }

        //print pass, min, index
        cout << "Pass " << i + 1 << ": min = " << arr[minIdx] << " at index " << minIdx << " -> ";

        // if minIdx != i:
        if (minIdx != i){
            swap(arr[i], arr[minIdx]); // swap(arr[i], arr[minIdx])
            swaps+=1;
        }

        // print array
        printArray(arr, n);


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
    int swaps = 0;

    // Original array
    cout << "Original: ";
    printArray(A, n);

    // call the sorting function
    selectionSort(A, n, comparisons, swaps);
    cout << "Sorted: ";
    printArray(A, n); // print the sorted array

    // print number of comparisons and swaps
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;;
}
