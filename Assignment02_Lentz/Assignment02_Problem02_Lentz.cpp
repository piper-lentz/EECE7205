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
// Problem 2: Insertion Sort
//===============================================================


// Function 1: prints the n elements of arr on one line, separated by spaces
void printArray(const int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


// Function 2: sorts arr in increasing order (the name changes per problem)
void insertionSort(int arr[], int n, int& comparisons, int& shifts){    
    // set up comparisons and swaps
    comparisons = 0;
    shifts = 0;
    
    // for i from 0 to n-1:
    for (int i = 0; i<=n-1; i++){
        // key = array[i]
        int key = arr[i]; 
        // j = i-1
        int j = i-1;

        // while j >= 0 and array[j] > key:
        while (j >= 0){
            // add count to comparisons
            comparisons += 1;

            // if arr[j]> key
            if (arr[j] > key){
                // array[j+1] = array[j]
                arr[j+1] = arr[j];
                // j = j-1
                j = j-1;
                // add count to shifts
                shifts += 1;
            }

            else{
                break;
            }
        }

        // array[j+1] = key 
        arr[j+1] = key;

        //print key and array to show each pass
        cout << "  Pass " << i + 1 << ": ";
        cout << "Key: " << key << ": ";
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
    int shifts = 0;

    // Original array
    cout << "Original: ";
    printArray(A, n);

    // call the sorting function
    insertionSort(A, n, comparisons, shifts);
    cout << "Sorted: ";
    printArray(A, n); // print the sorted array

    // print number of comparisons and shifts
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total shifts: " << shifts << endl;

    return 0;
}
