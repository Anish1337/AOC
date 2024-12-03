using namespace std; 
#include <regex>
#include <string>
#include <fstream>
#include <iostream>

int main() {
    regex pattern(R"(mul\((\d+),(\d+)\))");
    smatch match;
    int sum = 0;
    ifstream inputFile("input.txt");
    string corrMem;
    string line;

    while(getline(inputFile,line)){
        corrMem += line;
    }
    

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
