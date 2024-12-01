using namespace std; 
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


// AOC1Part1_2024
int main() {
    vector<int> list1;
    vector<int> list2;
    int d1;
    int d2;
    int totalDist = 0;

    // make lists
    while (cin >> d1 >> d2){
        list1.push_back(d1);
        list2.push_back(d2);
    }
    // sort lists
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    // calculate totalDist
    for (int i = 0; i < list1.size(); i++){
        totalDist += abs(list1[i]-list2[i]);
    } 
    // print totalDist
    cout << totalDist;

    // success
    return 0;
}


