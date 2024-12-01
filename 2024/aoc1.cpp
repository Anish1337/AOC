using namespace std; 
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


// algorithm
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

    for (int i = 0; i < list1.size(); i++){
        totalDist += abs(list1[i]-list2[i]);
    } 

    cout << totalDist;
    return 0;
}


