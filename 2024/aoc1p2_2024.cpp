using namespace std; 
#include <iostream>
#include <vector>
#include <unordered_map>


// AOC1Part2_2024
int main() {
    vector<int> list1;
    vector<int> list2;
    int d1;
    int d2;
    int similarityScore = 0;

    // make lists
    while (cin >> d1 >> d2){
        list1.push_back(d1);
        list2.push_back(d2);
    }

    // count dups
    unordered_map<int, int> dups;
    for (int dup : list2){
        dups[dup]++;
    }

    // calculate simlarityScore
    for (int i = 0; i < list1.size(); i++){
        int temp = list1[i];
        similarityScore += temp*dups[temp]; 
    } 

    // print similarityScore
    cout << similarityScore;

    // success
    return 0;
}


