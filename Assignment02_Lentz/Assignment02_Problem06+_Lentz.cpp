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
// Problem 6+: Heap Sort
//===============================================================

// Function 1: prints the n elements of arr on one line, separated by spaces

void printArray(pair<int, char> arr[], int n){
    for (int i = 0; i < n; i++){
        cout << "(" << arr[i].first << "," << arr[i].second << ") ";
    }
    cout << endl;
}

//helper function siftDown
void siftDown(pair<int, char> arr[], int root, int size, int &swaps){
    while (2*root+1 < size){

        // index of child - just how the tree gets formatted
        int child = 2*root+1;

        if (child +1 < size and arr[child+1].first > arr[child].first){
            child+=1;
        }

        // if the root is bigger than child, break - it is in the right spot
        if (arr[root].first >= arr[child].first){
            break;
        }

        // if the child is bigger than the root, swap places
        swap(arr[root], arr[child]);

        // count swaps
        swaps++;
        root=child;
    }
}

// Function 2: sorts arr in increasing order (the name changes per problem)
int heapSort(pair<int, char> arr[], int n){

    // set swap counter
    int swaps = 0;

    for (int i=(n/2)-1; i>=0; i--){

        // siftDown
        siftDown(arr, i, n, swaps);
    }

    // print the array after the build-max-heap phase
    cout << "Max heap: ";
    printArray(arr, n);

    for (int end=n-1; end>=1; end--){

        swap(arr[0], arr[end]);

        siftDown(arr, 0, end, swaps);

        // print and and heap part
        cout << "End = " << end << endl;
        cout << "Heap: ";
        printArray(arr, end);

        // print sorted part
        cout << "Sorted: ";
        printArray(arr + end, n - end);
        cout << "===============" << endl;
    }

    return swaps;
}

int main() {

    // The given array and its size
    // Example with duplicate values
    pair<int, char> A[] = {{34,'A'}, {7,'A'}, {7,'B'}, {32,'C'}, {7,'C'}};

    int n = sizeof(A) / sizeof(A[0]);

    // original array
    cout << "Original: ";
    printArray(A, n);

    // heapsort
    int swaps = heapSort(A, n);

    // print sorted array
    cout << "Final Sorted: ";
    printArray(A, n);

    // print total number of swaps
    cout << "Total swaps inside siftDown: " << swaps << endl;
}
