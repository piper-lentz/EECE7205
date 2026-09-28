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
#include <iomanip> 
#include <chrono>  
#include <random>  
using namespace std;



//===============================================================
// Problem 7: Comparing all six sorting algorithms
//===============================================================

void printArray(const int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


//===============================================================
// Problem 1: Bubble Sort
//===============================================================
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

        //if swapped = False then
        if (swapped == false){
            break;
        }
    }
}


//===============================================================
// Problem 2: Insertion Sort
//===============================================================
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

    }
}


//===============================================================
// Problem 3: Selection Sort
//===============================================================
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

        // if minIdx != i:
        if (minIdx != i){
            swap(arr[i], arr[minIdx]); // swap(arr[i], arr[minIdx])
            swaps+=1;
        }

    }
}


//===============================================================
// Problem 4: Quick Sort
//===============================================================
// partition helper function
int partition(int arr[], int low, int high, int& comparisons){
    int pivot = arr[high];
    int i = low-1;

    for (int j=low; j<= high-1; j++){
        comparisons += 1;

        if (arr[j] <= pivot){
            i = i+1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]); 

    return i+1;
}

void quickSort(int arr[], int low, int high, int& comparisons){ 
    if (low < high){

        int p = partition(arr, low, high, comparisons);

        // sort left side
        quickSort(arr, low, p-1, comparisons); 

        // sort right side
        quickSort(arr, p+1, high, comparisons);
    }
}


//===============================================================
// Problem 5: Merge Sort
//===============================================================

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

void mergeSort(int arr[], int low, int high, int &comparisons, int &lastMergeComparisons){ 
    if (low<high){
        int mid = (low+high)/2;

        mergeSort(arr, low, mid, comparisons, lastMergeComparisons); // sort left side of array
        mergeSort(arr, mid+1, high, comparisons, lastMergeComparisons); // sort right side of array 
        merge(arr, low, mid, high, comparisons, lastMergeComparisons); // merge arrays together in sorted order 
    }

}


//===============================================================
// Problem 6: Heap Sort
//===============================================================
//helper function siftDown
void siftDown(int arr[], int root, int size, int &swaps, int &comparisons){ 

    while (2*root+1 < size){

        // index of child - just how the tree gets formatted
        int child = 2*root+1;

        if (child +1 < size){
            comparisons+=1; // add to comparisons
            if (arr[child+1] > arr[child]){
                child+=1;
            }
        }

        comparisons+=1; // add to comparisons

        // if the root is bigger than child, break - it is in the right spot
        if (arr[root]>=arr[child]){
            break;
        }

        // if the child is bigger than the root, swap places
        swap(arr[root], arr[child]);

        // count swaps
        swaps++;

        root=child;
    }
}

int heapSort(int arr[], int n, int &comparisons){

    // set swap counter
    int swaps = 0;
    comparisons = 0; // reset comparison counter

    for (int i=(n/2)-1; i>=0; i--){

        // siftDown
        siftDown(arr, i, n, swaps, comparisons); 
    }

    for (int end=n-1; end>=1; end--){

        swap(arr[0], arr[end]);
        siftDown(arr, 0, end, swaps, comparisons); 

    }

    return swaps;
}


//===============================================================
// Helpers for running any of the six sort methods by number
//===============================================================
const int num_Algos = 6;
const char* names[num_Algos] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Quick Sort", "Merge Sort", "Heap Sort"};

//sorts arr with algorithm number "algo" and returns the number of comparisons
int runSort(int algo, int arr[], int n){
    int comparisons = 0;
    int other = 0; 

    if (algo == 0){
        bubbleSort(arr, n, comparisons, other);
    }
    else if (algo == 1){
        insertionSort(arr, n, comparisons, other);
    }
    else if (algo == 2){
        selectionSort(arr, n, comparisons, other);
    }
    else if (algo == 3){
        quickSort(arr, 0, n-1, comparisons);
    }
    else if (algo == 4){
        mergeSort(arr, 0, n-1, comparisons, other);
    }
    else{
        heapSort(arr, n, comparisons);
    }

    return comparisons;
}


// Main function
int main() {

    //===========================================================
    // Comparisons on A, sorted A, and reversed A
    //===========================================================

    // given array and its size
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int sortedA[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int reversedA[] = {62, 34, 32, 23, 19, 14, 7, 5};
    int n = sizeof(A) / sizeof(A[0]);

    // A, sorted A, reversed A
    vector<int> inputs[3];
    inputs[0].assign(A, A + n); // A
    inputs[1].assign(sortedA, sortedA + n);  // sorted A
    inputs[2].assign(reversedA, reversedA + n); // revered A

    cout << "A:        ";
    printArray(inputs[0].data(), n);
    cout << "Sorted:   ";
    printArray(inputs[1].data(), n);
    cout << "Reversed: ";
    printArray(inputs[2].data(), n);
    cout << endl;

    // runs each algorithm on A, sorted A, revered A
    cout << "Number of comparisons (n = " << n << ")" << endl;
    cout << left << setw(18) << "Algorithm" << right << setw(10) << "A" << setw(10) << "Sorted" << setw(10) << "Reversed" << endl;
    for (int a = 0; a < num_Algos; a++){
        cout << left << setw(18) << names[a];
        for (int k = 0; k < 3; k++){
            vector<int> copy = inputs[k];
            int comps = runSort(a, copy.data(), n);
            cout << right << setw(10) << comps;
        }
        cout << endl;
    }
    cout << endl;

    //===========================================================
    // Timing on random arrays
    //===========================================================

    const int num_Sizes = 3;
    int sizes[num_Sizes] = {1000, 5000, 10000};

    mt19937 rng(12345); // fixed seed so the random data is the same every run
    uniform_int_distribution<int> dist(1, 100000);

    double times[num_Algos][num_Sizes];   // time in milliseconds 
    vector<int> results[num_Algos][num_Sizes];  // the sorted output of each algorithm 

    for (int s = 0; s < num_Sizes; s++){
        // make the random data once per size
        vector<int> data(sizes[s]);
        for (int i = 0; i < sizes[s]; i++){
            data[i] = dist(rng);
        }

        for (int a = 0; a < num_Algos; a++){
            vector<int> arr = data; // fresh copy of the same random data 

            auto start = chrono::steady_clock::now();
            runSort(a, arr.data(), sizes[s]);
            auto stop = chrono::steady_clock::now();

            times[a][s] = chrono::duration<double, milli>(stop - start).count(); 
            results[a][s] = arr; 
        }
    }

    cout << "Sort time in milliseconds (random integers 1-100000)" << endl; 
    cout << left << setw(18) << "Algorithm";
    for (int s = 0; s < num_Sizes; s++){
        cout << right << setw(12) << ("n = " + to_string(sizes[s]));
    }
    cout << endl;
    cout << fixed << setprecision(3);
    for (int a = 0; a < num_Algos; a++){
        cout << left << setw(18) << names[a];
        for (int s = 0; s < num_Sizes; s++){
            cout << right << setw(12) << times[a][s];
        }
        cout << endl;
    }
    cout << endl;


    //===========================================================
    // Check the sorted output (first 10 elements of each sorted array)
    //===========================================================

    for (int s = 0; s < num_Sizes; s++){
        cout << "First 10 elements after sorting n = " << sizes[s] << ":" << endl;

        for (int a = 0; a < num_Algos; a++){
            cout << left << setw(16) << names[a] << ": ";
            printArray(results[a][s].data(), 10);
        }

        cout << endl;
    }

    return 0;
}