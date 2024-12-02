// libs
using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>


// function prototypes
bool increasing(vector<int> arr);
bool decreasing(vector<int> arr);
bool validDiff(vector<int> arr);
bool dampener(vector<int> arr);
vector<int> readline(string buffer);

// AOC2p2_2024
int main() {
    int safe = 0;
    string buffer;

    while (getline(cin, buffer)) {
        vector<int> arr = readline(buffer);

        // check safe report 
        if ((increasing(arr)||decreasing(arr))&&validDiff(arr)) {
            safe += 1;
        }else{
            // check if dampener relaxes condition
            if (dampener(arr)){
                safe += 1;
            }
        }
    }

    cout << safe << endl;

    return 0;
}

// validDiff helper
bool validDiff(vector<int> arr) {
    bool isValid = true;
    for (int i = 1; i < arr.size(); i++) {
        // calc diff
        int diff = abs(arr[i] - arr[i - 1]);
        // check valid
        if (diff < 1 || diff > 3) {
            isValid = false;
            break;
        }
    }
    return isValid;
}

bool increasing(vector<int> arr) {
    bool isIncrease = true;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] >= arr[i]) {
            isIncrease = false;
        }
    }
    return isIncrease;
}

bool decreasing(vector<int> arr) {
    bool isDecrease = true;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] <= arr[i]) {
            isDecrease = false;
        }
    }
    return isDecrease;
}

// dampener condition
bool dampener(vector<int> arr) {
    bool isValid = false;
    for (int i = 0; i < arr.size(); i++) {
        vector<int> newArr = arr;

        // erase moves the ith element
        newArr.erase(newArr.begin() + i);
        // check dampen condition
        if ((increasing(newArr) || decreasing(newArr)) && validDiff(newArr)) {
            isValid = true;
            break;
        }
    }
    return isValid;
}

// string to int conversion
vector<int> readline(string buffer) {
    vector<int> arr;
    stringstream ss(buffer);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

