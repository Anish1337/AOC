using namespace std; 
#include <regex>
#include <string>
#include <fstream>
#include <iostream>

int main() {
    // regex
    regex pattern(R"(mul\((\d+),(\d+)\))");
    regex dopattern(R"");
    regex dontpattern(R"");
    smatch match;
    
    // input
    ifstream inputFile("input.txt");
    string corrMem;
    string line;
    while(getline(inputFile,line)){
        corrMem += line;
    }

    // aoc3p2_2024 
    int sum = 0;
    mult = true;

    while(regex_search(corrMem, match, pattern)){
        // extract x,y index is capture group
        int x = stoi(match[1].str());
        int y = stoi(match[2].str());

        // add to output
        sum += x * y;

        // parse through remainder of match
        corrMem = match.suffix().str();
    }

    //output
    cout << sum <<endl;
    return 0;
}
