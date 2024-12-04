using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


// isWordAt helper function
bool isWordAt(const vector<string>& grid, int x, int y, int dx, int dy, const string& word) {
    int n = grid.size();
    int m = grid[0].size();
    int len = word.length();
    
    for (int i = 0; i < len; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;

        // bounds
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != word[i]) {
            return false;
        }
    }
    return true;
}

// algo
int countWordOccurrences(const vector<string>& grid, const string& word) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    // 8 directions
    vector<pair<int, int>> directions = {
        {0, 1},   // 6
        {0, -1},  // 4
        {1, 0},   // 2
        {-1, 0},  // 8
        {1, 1},   // 3
        {-1, -1}, // 7
        {1, -1},  // 1
        {-1, 1}   // 9
    };

    // go through each cell in grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // check all diretcions
            for (const auto& dir : directions) {
                int dx = dir.first;
                int dy = dir.second;
                if (isWordAt(grid, i, j, dx, dy, word)) {
                    count += 1; 
                }
            }
        }
    }
    return count;
}

// aoc4p1_2024
int main() {
    // input
    ifstream inputFile("input.txt");
    vector<string> grid;
    string line;
    while (getline(inputFile, line)) {
        grid.push_back(line);
    }
    inputFile.close();

    // word to search
    string word = "XMAS";
    
    // output
    cout << countWordOccurrences(grid, word) << endl;
    return 0;
}

