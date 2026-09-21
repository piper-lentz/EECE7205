// Assignment01_Lentz.cpp
// EECE 7205 - Assignment 01
// One program, one menu, one function per problem.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------- Helper: print a vector ----------
void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// ---------- Problem 1: Sum of an array ----------
int sumArray(const vector<int>& arr) {
    int total = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        total += arr[i];
    }
    return total;
}

void runSum() {
    cout << "\n--- Problem 1: Sum of an Array ---\n";
    vector<int> arr = {4, 8, 15, 16, 23, 42};
    cout << "Input:  ";
    printVector(arr);
    cout << "Sum:    " << sumArray(arr) << endl;
}

// ---------- Problem 2: Largest number in an array ----------
int findMax(const vector<int>& arr) {
    int best = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > best) best = arr[i];
    }
    return best;
}

void runMax() {
    cout << "\n--- Problem 2: Largest Number in an Array ---\n";
    vector<int> arr = {7, 3, 19, 2, 11};
    cout << "Input:  ";
    printVector(arr);
    cout << "Max:    " << findMax(arr) << endl;
}

// ---------- Problem 3: Reverse an array ----------
void reverseArray(vector<int>& arr) {
    int left = 0, right = (int)arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void runReverse() {
    cout << "\n--- Problem 3: Reverse an Array ---\n";
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Input:  ";
    printVector(arr);
    reverseArray(arr);
    cout << "Output: ";
    printVector(arr);
}

// ---------- Problem 4: Count even numbers ----------
int countEvens(const vector<int>& arr) {
    int count = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 == 0) count++;
    }
    return count;
}

void runCountEvens() {
    cout << "\n--- Problem 4: Count Even Numbers ---\n";
    vector<int> arr = {1, 2, 3, 4, 5, 6, 10};
    cout << "Input:  ";
    printVector(arr);
    cout << "Evens:  " << countEvens(arr) << endl;
}

// ---------- Problem 5: Palindrome check ----------
bool isPalindrome(const string& s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

void runPalindrome() {
    cout << "\n--- Problem 5: Palindrome Check ---\n";
    string word = "racecar";
    cout << "Input:  " << word << endl;
    cout << "Palindrome? " << (isPalindrome(word) ? "Yes" : "No") << endl;
}

// ---------- Problem 6: Factorial ----------
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void runFactorial() {
    cout << "\n--- Problem 6: Factorial ---\n";
    int n = 5;
    cout << "Input:  " << n << endl;
    cout << n << "! = " << factorial(n) << endl;
}

// ---------- Problem 7: First n Fibonacci numbers ----------
vector<int> fibonacci(int n) {
    vector<int> result;
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        result.push_back(a);
        int next = a + b;
        a = b;
        b = next;
    }
    return result;
}

void runFibonacci() {
    cout << "\n--- Problem 7: Fibonacci Numbers ---\n";
    int n = 10;
    cout << "First " << n << " numbers: ";
    printVector(fibonacci(n));
}

// ---------- Problem 8: Prime check ----------
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void runPrime() {
    cout << "\n--- Problem 8: Prime Check ---\n";
    int nums[] = {2, 9, 17, 20};
    for (int i = 0; i < 4; ++i) {
        cout << nums[i] << " is " << (isPrime(nums[i]) ? "prime" : "not prime") << endl;
    }
}

// ---------- Problem 9: Count vowels in a string ----------
int countVowels(const string& s) {
    int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';   // make lowercase
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
    }
    return count;
}

void runVowels() {
    cout << "\n--- Problem 9: Count Vowels ---\n";
    string text = "Hello World";
    cout << "Input:  " << text << endl;
    cout << "Vowels: " << countVowels(text) << endl;
}

// ---------- Problem 10: Celsius to Fahrenheit ----------
double celsiusToFahrenheit(double c) {
    return c * 9.0 / 5.0 + 32.0;
}

void runTemperature() {
    cout << "\n--- Problem 10: Celsius to Fahrenheit ---\n";
    double temps[] = {0, 25, 100};
    for (int i = 0; i < 3; ++i) {
        cout << temps[i] << " C = " << celsiusToFahrenheit(temps[i]) << " F" << endl;
    }
}

// ---------- Main: menu ----------
int main() {
    int choice = -1;
    while (choice != 0) {
        cout << "\n===== Assignment 01 Menu =====\n"
             << " 1. Sum of an Array\n"
             << " 2. Largest Number in an Array\n"
             << " 3. Reverse an Array\n"
             << " 4. Count Even Numbers\n"
             << " 5. Palindrome Check\n"
             << " 6. Factorial\n"
             << " 7. Fibonacci Numbers\n"
             << " 8. Prime Check\n"
             << " 9. Count Vowels\n"
             << "10. Celsius to Fahrenheit\n"
             << " 0. Exit\n"
             << "Choose: ";

        if (!(cin >> choice)) {            // non-numeric input
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        }

        switch (choice) {
            case 1:  runSum();         break;
            case 2:  runMax();         break;
            case 3:  runReverse();     break;
            case 4:  runCountEvens();  break;
            case 5:  runPalindrome();  break;
            case 6:  runFactorial();   break;
            case 7:  runFibonacci();   break;
            case 8:  runPrime();       break;
            case 9:  runVowels();      break;
            case 10: runTemperature(); break;
            case 0:  cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    }
    return 0;
}
