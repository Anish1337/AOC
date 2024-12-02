// libs
using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include<sstream>

// function prototypes
bool increasing(vector<int> arr);
bool decreasing(vector<int> arr);
bool validDiff(vector<int> arr);
vector<int> readline(string buffer);

// AOC2p1_2024
int main(){
    int safe = 0;
    string buffer;

    while(getline(cin, buffer)) {
    vector<int> arr = readline(buffer);
    
    // check safe report
    if ((increasing(arr) || decreasing(arr)) && validDiff(arr)){
        safe += 1;
    }
    }

    // output num safe reports
    cout << safe;
    
    // success
    return 0;
}

// validDiff helper
bool validDiff(vector<int> arr) {
    bool isValid = true;
    for(int i = 1; i < arr.size(); i++){
            // calc diff
            int diff = abs(arr[i] - arr[i-1]); 
            // check valid
            if (diff < 1 || diff > 3){
                isValid = false;
                break;
            }
        }
    
    return isValid; 
}

bool increasing(vector<int> arr) {
    bool isIncrease = true;
    for( int i = 1; i < arr.size(); i++){
        if(arr[i-1]>arr[i]){
            isIncrease = false;
            break;
        }
    }
    return isIncrease;
}

bool decreasing(vector<int> arr){
    bool isDecrease = true;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i-1]<arr[i]){
            isDecrease = false;
            break;
        }
    }
    return isDecrease;
}


// string to int
vector<int> readline(string buffer) {
    vector<int> arr;
    stringstream ss(buffer);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

