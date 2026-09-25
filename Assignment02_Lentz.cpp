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
using namespace std;

//===============================================================
// Problem 1: Bubble Sort
//===============================================================

// Function 1: prints the n elements of arr on one line, separated by spaces
void printArray(const int arr[], int n);

// Function 2: sorts arr in increasing order (the name changes per problem)
void bubbleSort(int arr[], int n);

int main() {
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Original: ";
    printArray(A, n);
    bubbleSort(A, n); // calls printArray inside to show each step
    cout << "Sorted: ";
    printArray(A, n);
    return 0;
}