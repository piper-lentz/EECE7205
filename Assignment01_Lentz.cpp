// Hello! I wanted to add up here that I used Claude to help me set up the display menu, parsing helpers, and voids
//since I had never heard of those before and wasn't sure why it wasn't working and it was just an organizational 
//aspect of the assignment. 


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


// Input parsing helpers
// Parses a single line of space-separated integers into a vector<int>
vector<int> parseInts(const string& line) {
    vector<int> result;
    stringstream ss(line);
    int x;
    while (ss >> x) result.push_back(x);
    return result;
}

// Splits a line on a delimiter character (e.g. ';') into trimmed sub-strings
vector<string> splitOn(const string& line, char delim) {
    vector<string> parts;
    stringstream ss(line);
    string part;
    while (getline(ss, part, delim)) {
        size_t start = part.find_first_not_of(" \t");
        size_t end = part.find_last_not_of(" \t");
        if (start != string::npos)
            parts.push_back(part.substr(start, end - start + 1));
    }
    return parts;
}



// Run function declarations — read input, call the algorithm, print result

void runProblem1();
void runProblem2a();
void runProblem2b();
void runProblem3();
void runProblem4();
void runProblem5();
void runProblem6a();  
void runProblem6b(); 
void runProblem7();   
void runProblem8();   
void runProblem9();   
void runProblem10();  

//===============================================================
// Menu
//===============================================================
void showMenu() {
    cout << "\n-----------------------------------\n";
    cout << "   Assignment 01 - Algorithm Menu\n";
    cout << "-----------------------------------\n";
    cout << " 1. Merge Intervals\n";
    cout << " 2a. Group 0s, 1s, and 2s - counting-based\n";
    cout << " 2b. Group 0s, 1s, and 2s - Dutch national flag\n";
    cout << " 3. Largest Number\n";
    cout << " 4. Group Anagrams\n";
    cout << " 5. Meeting Overlap\n";
    cout << " 6a. K Closest Points - sorting\n";
    cout << " 6b. K closest Points - heap\n";
    cout << " 7. Top K Frequent Elements \n";
    cout << " 8. Merged Sorted Arrays\n";
    cout << " 9. Kth Largest Element\n";
    cout << "10. Inversion Count\n";
    cout << " 0. Exit\n";
    cout << "-----------------------------------\n";
    cout << "Choose a problem: ";
}

int main() {
    string choice;

    do {
        showMenu();

        if (!(cin >> choice)) {
            break;   // input closed (e.g. Ctrl+D), stop instead of looping forever
        }

        if      (choice == "1")  runProblem1();
        else if (choice == "2a") runProblem2a();
        else if (choice == "2b") runProblem2b();
        else if (choice == "3")  runProblem3();
        else if (choice == "4")  runProblem4();
        else if (choice == "5")  runProblem5();
        else if (choice == "6a") runProblem6a();
        else if (choice == "6b") runProblem6b();
        else if (choice == "7")  runProblem7();
        else if (choice == "8")  runProblem8();
        else if (choice == "9")  runProblem9();
        else if (choice == "10") runProblem10();
        else if (choice == "0")  cout << "Goodbye.\n";
        else                     cout << "Invalid choice. Try again.\n";
    } while (choice != "0");

    return 0;
}

//===============================================================
// Problem 1: Merge Intervals
//===============================================================

vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> intervals) {
    int n = intervals.size();

    // if no intervals, return an empty vector
    if (n == 0) {
        return {};
    }

    // bubble sort by start time 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 -i; j++) {
            if (intervals[j].first > intervals[j + 1].first) {
                pair<int,int> temp = intervals[j];
                intervals[j] = intervals[j + 1];
                intervals[j + 1] = temp;
            }
        }
    }

    // merge overlapping intervals
    vector<pair<int,int>> mergedIntervals;
    pair<int,int> currentInterval = intervals[0];
    for (int i = 1; i < n; i++) {
        if (currentInterval.second >= intervals[i].first) {
            currentInterval.second = max(currentInterval.second, intervals[i].second);
        }
          else {
            mergedIntervals.push_back(currentInterval);
            currentInterval = intervals[i];
        }
    }
    mergedIntervals.push_back(currentInterval);

    return mergedIntervals;
}

void runProblem1() {
    cout << "\n-- Merge Intervals --\n";
    cout << "Enter intervals separated by semicolons, as: start end\n";
    cout << "Example: 1 3; 2 6; 8 10; 15 18\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<string> groups = splitOn(line, ';');
    vector<pair<int,int>> intervals;
    for (const string& g : groups) {
        vector<int> vals = parseInts(g);
        intervals.push_back({vals[0], vals[1]});
    }

    if (intervals.empty()) {
        cout << "No intervals were input\n";
        return;
    }

    vector<pair<int,int>> result = mergeIntervals(intervals);

    cout << "Merged intervals: ";
    for (auto& iv : result) cout << "[" << iv.first << "," << iv.second << "] ";
    cout << "\n";
}

//===============================================================
// Problem 2a: Group 0s, 1s, and 2s - counting-based
//===============================================================

vector<int> groupZeroOneTwo(vector<int> values) {
    int count0 = 0; 
    int count1 = 0; 
    int count2 = 0;
    int n = values.size();

    if (n == 0) {
        return {};
    }

    // ---- counting 0s, 1s, 2s ----
    for (int i = 0; i < n; i++) {
        if (values[i] == 0) {
            count0+=1;
        } else if (values[i] == 1) {
            count1+=1;
        } else if (values[i] == 2) {
            count2+=1;
        } else {
            cout << "Not a valid input: " << values[i] << "\n";
        }
    }

    // ---- overwrite in place ----
    int index = 0;
    for (int i = 0; i < count0; i++) {
        values[index] = 0;
        index+=1;
    }
    for (int i = 0; i < count1; i++) {
        values[index] = 1;
        index+=1;
    }
    for (int i = 0; i < count2; i++) {
        values[index] = 2;
        index+=1;
    }

    return values;
}

void runProblem2a() {
    cout << "\n-- Group 0s, 1s, and 2s - counting-based --\n";
    cout << "Enter values (only 0, 1, 2) separated by spaces.\n";
    cout << "Example: 2 0 1 2 0 1 0\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<int> values = parseInts(line);

    if (values.empty()) {
        cout << "No values input\n";
        return;
    }

    vector<int> result = groupZeroOneTwo(values);

    cout << "Grouped result: ";
    for (int v : result) cout << v << " ";
    cout << "\n";
}

//===============================================================
// Problem 2b: Group 0s, 1s, and 2s - Dutch national flag
//===============================================================

vector<int> dutchFlag(vector<int> values) {
    int n = values.size();

    if (n == 0) {
        return {};
    }

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (values[mid] == 0) {
            int temp = values[mid];
            values[mid] = values[low];
            values[low] = temp;
            mid+=1;
            low+=1;
        } else if (values[mid] == 1) {
            mid+=1;
        } else if (values[mid] == 2) {
            int temp = values[mid];
            values[mid] = values[high];
            values[high] = temp;
            high--;
        } else {
            cout << "Not a valid input: " << values[mid] << "\n";
            mid+=1;
        }
    }

    return values;
}

void runProblem2b() {
    cout << "\n-- Dutch National Flag --\n";
    cout << "Enter values (only 0, 1, 2) separated by spaces.\n";
    cout << "Example: 2 0 1 2 0 1 0\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<int> values = parseInts(line);

    if (values.empty()) {
        cout << "Values is empty\n";
        return;
    }

    vector<int> result = dutchFlag(values);

    cout << "Result: ";
    for (int v : result) cout << v << " ";
    cout << "\n";
}

//===============================================================
// Problem 3: Largest Number
//===============================================================

string largestNumber(vector<int> values) {
    int n = values.size();

    if (n == 0) {
        return "Values is empty";
    }

    // ---- convert each value to a string ----
    vector<string> valuesStr;
    for (int i = 0; i < n; i++) {
        valuesStr.push_back(to_string(values[i]));
    }

    // ---- sort so that concatenating in order gives the largest result ----
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (valuesStr[j] + valuesStr[j + 1] < valuesStr[j + 1] + valuesStr[j]) {
                string temp = valuesStr[j];
                valuesStr[j] = valuesStr[j + 1];
                valuesStr[j + 1] = temp;
            }
        }
    }

    // ---- concatenate ----
    string result = "";
    for (int i = 0; i < n; i++) {
        result += valuesStr[i];
    }

    return result;
}

void runProblem3() {
    cout << "\n-- Largest Number --\n";
    cout << "Enter non-negative integers separated by spaces.\n";
    cout << "Example: 3 30 34 5 9\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<int> values = parseInts(line);

    string result = largestNumber(values);

    cout << "Largest number: " << result << "\n";
}


// Problem 4: Group Anagrams

vector<string> parseWords(const string& line) {
    vector<string> result;
    stringstream ss(line);
    string word;
    while (ss >> word) result.push_back(word);
    return result;
}

//helper to sort letters in words in alphabetical order
string sortCharactersInWord(string word) {
    sort(word.begin(), word.end());
    return word;
}

vector<vector<string>> groupAnagrams(vector<string> words) {
    int n = words.size();

    if (n == 0) {
        return {};
    }

    map<string, vector<string>> wordMap;

    for (int i = 0; i < n; i++) {
        string key = sortCharactersInWord(words[i]);
        wordMap[key].push_back(words[i]);
    }

    vector<vector<string>> result;
    for (auto& entry : wordMap) {
        result.push_back(entry.second);
    }

    return result;
}

void runProblem4() {
    cout << "\n-- Group Anagrams --\n";
    cout << "Enter words separated by spaces.\n";
    cout << "Example: eat tea tan ate nat bat\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<string> words = parseWords(line);

    if (words.empty()) {
        cout << "Words is empty\n";
        return;
    }

    vector<vector<string>> result = groupAnagrams(words);

    cout << "Grouped anagrams: ";
    for (auto& group : result) {
        cout << "[";
        for (int i = 0; i < (int)group.size(); i++) {
            cout << group[i];
            if (i < (int)group.size() - 1) cout << " ";
        }
        cout << "] ";
    }
    cout << "\n";
}


// Problem 5: Meeting Overlap

bool meetingOverlap(vector<pair<int,int>> intervals) {
    int n = intervals.size();

    // bubble sort by start time 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 2 - i; j++) {
            if (intervals[j].first > intervals[j + 1].first) {
                pair<int,int> temp = intervals[j];
                intervals[j] = intervals[j + 1];
                intervals[j + 1] = temp;
            }
        }
    }

    //check every adjacent pair for overlap
    for (int i = 0; i < n - 1; i++) {
        if (intervals[i].second > intervals[i + 1].first) {
            return false;
        }
    }
    return true; 
}

void runProblem5() {
    cout << "\n-- Meeting Overlap --\n";
    cout << "Enter intervals separated by semicolons, as: start end\n";
    cout << "Example: 1 3; 5 6; 8 10\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<string> groups = splitOn(line, ';');
    vector<pair<int,int>> intervals;
    for (const string& g : groups) {
        vector<int> vals = parseInts(g);
        intervals.push_back({vals[0], vals[1]});
    }

    if (intervals.empty()) {
        cout << "Intervals is empty\n";
        return;
    }

    bool result = meetingOverlap(intervals);

    cout << "No overlaps: " << (result ? "True" : "False") << "\n";
}



// Problem 6a: K Closest Points - sorting

vector<pair<int,int>> closePointsa(vector<pair<int,int>> points, int k) {
    int n = points.size();

    vector<pair<long long, pair<int,int>>> key;
    for (int i = 0; i < n; i++) {
        long long dist = (long long)points[i].first * points[i].first + (long long)points[i].second * points[i].second;
        key.push_back({dist, points[i]});
    }

    //bubble sort by distance
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (key[j].first > key[j + 1].first) {
                auto temp = key[j];
                key[j] = key[j + 1];
                key[j + 1] = temp;
            }
        }
    }

    // return k closest points
    vector<pair<int,int>> result;
    for (int i = 0; i < k; i++) {
        result.push_back(key[i].second);
    }
    return result;
}

void runProblem6a() {
    cout << "\n-- K Closest Points --\n";
    cout << "Enter points separated by semicolons, as: x y\n";
    cout << "Example: 1 3; -2 2; 5 8; 0 1\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<string> groups = splitOn(line, ';');
    vector<pair<int,int>> points;
    for (const string& g : groups) {
        vector<int> vals = parseInts(g);
        points.push_back({vals[0], vals[1]});
    }

    if (points.empty()) {
        cout << "Points is empty\n";
        return;
    }

    cout << "Enter k: ";
    int k;
    cin >> k;

    if (k <= 0) {
        cout << "Make k a positive integer\n";
        return;
    }

    if (k > (int)points.size()) {
        cout << "k is larger than the number of points available.\n";
        return;
    }

    vector<pair<int,int>> result = closePointsa(points, k);

    cout << "Closest points: ";
    for (auto& p : result) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";
}


// Problem 6b: Closest k points - heap


vector<pair<int,int>> closePointsb(vector<pair<int,int>> points, int k) {
    int n = points.size();

    // Max-heap to store pairs of {distance, point}
    priority_queue<pair<long long, pair<int,int>>> maxHeap;

    for (int i = 0; i < n; i++) {
        long long dist = (long long)points[i].first * points[i].first + (long long)points[i].second * points[i].second;

        if (maxHeap.size() < (size_t)k) {
            maxHeap.push({dist, points[i]});
        } 
        else if (dist < maxHeap.top().first) {
            maxHeap.pop(); // pop out largest dist in heap
            maxHeap.push({dist, points[i]});
        }
    }

    // Extract k points from heap into result vector
    vector<pair<int,int>> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    // reverse so results go from closest to farthest
    reverse(result.begin(), result.end());

    return result;
}

void runProblem6b() {
    cout << "\n-- K Closest Points to Origin --\n";
    cout << "Enter points separated by semicolons, as: x y\n";
    cout << "Example: 1 3; -2 2; 5 8; 0 1\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<string> groups = splitOn(line, ';');
    vector<pair<int,int>> points;
    for (const string& g : groups) {
        vector<int> vals = parseInts(g);
        if (vals.size() >= 2) {
            points.push_back({vals[0], vals[1]});
        }
    }

    if (points.empty()) {
        cout << "Points is empty\n";
        return;
    }

    cout << "Enter k: ";
    int k;
    if (!(cin >> k)) {
        cout << "Make k a positive integer\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (k <= 0 || k > (int)points.size()) {
        cout << "Make k a positive integer less than or equal to number of points\n";
        return;
    }

    vector<pair<int,int>> result = closePointsb(points, k);

    cout << "Closest points: ";
    for (auto& p : result) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << "\n";
}

//===============================================================
// Problem 7: Top K Frequent Elements 
//===============================================================

vector<int> frequency(vector<int> values, int k) {
    int n = values.size();

    // if values is empty
    if (n == 0) {
        return {};
    }

    // if k < 0 
    if (k < 0) {
        return {};
    }

    // find frequency of integers in values
    map<int, int> myMap;
    for (int i = 0; i < n; i++) {
        int key = values[i];
        if (myMap.find(key) == myMap.end()) {
            myMap[key] = 1;
        } else {
            myMap[key] += 1;
        }
    }

    // copy map into list of (value, count) to sort
    vector<pair<int, int>> pairs;
    for (auto const& entry : myMap) {
        pairs.push_back({entry.first, entry.second}); // first = key, second = count
    }

    // sort in descending order by count
    int m = pairs.size();
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - 1 - i; j++) {
            if (pairs[j].second < pairs[j + 1].second || 
               (pairs[j].second == pairs[j + 1].second && pairs[j].first > pairs[j + 1].first)) {
                swap(pairs[j], pairs[j + 1]);
            }
        }
    }

    // give first k values
    vector<int> result;
    int limit = min(k, m); // in case k is more than n
    for (int i = 0; i < limit; i++) {
        result.push_back(pairs[i].first);
    }

    return result;
}

void runProblem7() {
    cout << "\n-- Top K Frequent Elements --\n";
    cout << "Enter values separated by spaces.\n";
    cout << "Example: 1 1 1 2 2 3\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<int> values = parseInts(line);

    if (values.empty()) {
        cout << "Values is empty\n";
        return;
    }

    cout << "Enter k: ";
    int k;
    if (!(cin >> k)) {
        cout << "Make k a positive integer\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (k <= 0) {
        cout << "Make k a positive integer\n";
        return;
    }

    vector<int> result = frequency(values, k);

    cout << "Top " << k << " frequent elements: ";
    for (int v : result) cout << v << " ";
    cout << "\n";
}

//===============================================================
// Problem 8: Merged Sorted Arrays
//===============================================================

vector<int> mergeKSortedArrays(vector<vector<int>> arrays) {
    vector<int> result;
    int k = arrays.size(); // Number of arrays

    // min-heap 
    priority_queue<tuple<int, int, int>, 
                   vector<tuple<int, int, int>>, 
                   greater<tuple<int, int, int>>> heap;

    //put first element of each array in heap
    for (int i = 0; i < k; i++) {
        if (!arrays[i].empty()) {
            heap.push({arrays[i][0], i, 0});
        } else {
            cout << "array " << i << " is empty\n";
        }
    }

    // get min of heap and put it in result
    while (!heap.empty()) {
        auto [value, arrayidx, elementidx] = heap.top();
        heap.pop();
        result.push_back(value);

        // push next value from the same array into heap 
        int nextidx = elementidx + 1;
        if (nextidx < (int)arrays[arrayidx].size()) {
            heap.push({arrays[arrayidx][nextidx], arrayidx, nextidx});
        }
    }

    return result;
}

void runProblem8() {
    cout << "\n-- Merge K Sorted Arrays --\n";
    cout << "Enter each sorted array separated by semicolons.\n";
    cout << "Example: 1 4 7; 2 5 8; 3 6 9\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<string> groups = splitOn(line, ';');
    vector<vector<int>> arrays;
    for (const string& g : groups) {
        vector<int> vals = parseInts(g);
        if (!vals.empty()) {
            arrays.push_back(vals);
        }
    }

    if (arrays.empty()) {
        cout << "No arrays were input\n";
        return;
    }

    vector<int> result = mergeKSortedArrays(arrays);

    cout << "Merged array: ";
    for (int v : result) cout << v << " ";
    cout << "\n";
}

//===============================================================
// Problem 9: Kth Largest Element
//===============================================================

int kthLargestElement(vector<int> values, int k) {
    int n = values.size();

    if (n == 0) {
        return {}; 
    }

    // min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++) {
        int val = values[i];
        
        if (minHeap.size() < (size_t)k) {
            minHeap.push(val); 
        } 
        else if (val > minHeap.top()) {
            minHeap.pop();   
            minHeap.push(val); 
        }
    }

    return minHeap.top(); 
}

void runProblem9() {
    cout << "\n-- Kth Largest Element --\n";
    cout << "Enter values separated by spaces.\n";
    cout << "Example: 3 2 1 5 6 4\n";
    cout << "Input: ";

    cin.ignore();
    string line;
    getline(cin, line);

    vector<int> values = parseInts(line);

    if (values.empty()) {
        cout << "Values is empty\n";
        return;
    }

    cout << "Enter k: ";
    int k;
    if (!(cin >> k)) {
        cout << "Make k a positive integer\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (k <= 0 || k > (int)values.size()) {
        cout << "Make k a positive integer\n";
        return;
    }

    int result = kthLargestElement(values, k);

    cout << "The " << k << "-th largest element is: " << result << "\n";
}

//===============================================================
// Problem 10: Inversion Count
//===============================================================

int countInversions(vector<int> values) {
    int n = values.size();
    vector<int> temp(n);
    int count = 0;

    int width = 1;
    while (width < n) {
        for (int low = 0; low <= n - width - 1; low += 2 * width) {
            int mid = low + width - 1;
            int hi = min(low + 2 * width - 1, n - 1);
            int i = low;
            int j = mid + 1;
            int k = low;

            while (i <= mid && j <= hi) {
                if (values[i] <= values[j]) {
                    temp[k] = values[i];
                    k +=1;
                    i +=1;
                } else {
                    temp[k] = values[j];
                    k += 1;
                    j +=1;
                    count = count + (mid - i + 1);
                }
            }
            while (i <= mid) {
                temp[k] = values[i];
                k +=1;
                i += 1;
            }
            while (j <= hi) {
                temp[k] = values[j];
                k += 1;
                j += 1;
            }

            // copy temp[lo..hi] back into values[lo..hi]
            for (int x = low; x <= hi; x++) {
                values[x] = temp[x];
            }
        }
        width = width * 2;
    }

    return count;
}

void runProblem10() {
    cout << "\n-- Inversion Count --\n";
    cout << "Enter values separated by spaces.\n";
    cout << "Example: 2 4 1 3 5\n";
    cout << "Input: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line);

    vector<int> values = parseInts(line);

    if (values.empty()) {
        cout << "Values is empty\n";
        return;
    }

    int result = countInversions(values);

    cout << "Number of inversions: " << result << "\n";
}

