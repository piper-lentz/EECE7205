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
// Problem 1: Bubble Sort
//===============================================================


// Function 1: prints the n elements of arr on one line, separated by spaces
void printArray(const int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function 2: sorts arr in increasing order (the name changes per problem)
void bubbleSort(int arr[], int n, int& comparisons, int& swaps){    
    // set up comparisons and swaps
    comparisons = 0;
    swaps = 0;
    
    //for i from 0 to n-2:
    for (int i = 0; i<=n-2; i++){
        // swapped = False
        bool swapped = false;
        // for j from 0 to n-2-i:
        for (int j = 0; j<=n-2-i; j++){
            // add a count to comparisons
            comparisons += 1;
            //if array[j] > array[j+1]:
            if (arr[j]>arr[j+1]){
                //swap array[j], array[j+1]
                swap(arr[j], arr[j+1]);
                // add a count to swaps
                swaps += 1;
                //swapped = True
                swapped = true;
            }
        }
        //print array to show each pass
        cout << "Pass " << i + 1 << ": ";
        printArray(arr, n);

        //if swapped = False then
        if (swapped == false){
            break;
        }
    }
}


// Main function
int main() {
    // The given array and its size
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    // the sorted array for the check 
    // int A[] = {5, 7, 14, 19, 23, 32, 34, 62};
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
    bubbleSort(A, n, comparisons, swaps);
    cout << "Sorted: ";
    printArray(A, n); // print the sorted array

    // print number of comparisons and swaps
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    return 0;
}


