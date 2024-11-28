#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using std::cout;
using std::vector;
using std::pow;
using std::next_permutation;
using std::min;

// Determines if 'challenger' is a magic square
bool magicSquare(vector<vector<int>> input, vector<int> challenger) {

    const int MAGIC_CONSTANT = (input.size() * (pow(input.size(), 2) + 1)) / 2;

    // ROWS
    for (int i = 0; i < input.size(); i++) {

        int rowSum = 0;
        for(int j = 0; j < input[i].size(); j++) 
            rowSum += challenger[i * input.size() + j];

        if (rowSum != MAGIC_CONSTANT)
            return false;
    
    }

    // DIAGONALS

    int diagonalSum = 0;
    for (int i = 0; i < pow(input.size(), 2); i += input.size() + 1)
        diagonalSum += challenger[i];

    if (diagonalSum != MAGIC_CONSTANT)
        return false;

    diagonalSum = 0; // reset for the other diagonal

    for (int i = input.size() - 1; i <= pow(input.size(), 2) - input.size(); i += input.size() - 1)
        diagonalSum += challenger[i];

    if (diagonalSum != MAGIC_CONSTANT)
        return false;

    // COLUMNS
    for (int i = 0; i < input.size(); i++) {

        int columnSum = 0;
        for(int j = 0; j < input[i].size(); j++) 
            columnSum += challenger[j * input.size() + i];

        if (columnSum != MAGIC_CONSTANT)
            return false;     
    
    }

    return true;

}

// Determines the 'cost' to transform 'input' into 'challenger'
int costToMagicSquare(vector<vector<int>> input, vector<int> challenger) {

    int cost = 0;
    for (int i = 0; i < input.size(); i++)
        for (int j = 0; j < input[i].size(); j++)
            cost += abs(input[i][j] - challenger[i * input.size() + j]);

    return cost;

}

int formingMagicSquare(vector<vector<int>> s) {

    vector<int> challenger;
    for (int content = 1; content <= pow(s.size(), 2); content++)
        challenger.push_back(content);

    int cost = std::numeric_limits<int>::max();;
    do {

        if (magicSquare(s, challenger)) {

            int squareCost = costToMagicSquare(s, challenger);
            cost = min(cost, squareCost);

        }


    } while (next_permutation(challenger.begin(), challenger.end()));

    return cost;

}

int main() {

    vector<vector<int>> s { {5, 3, 4}, {1, 5, 8}, {6, 4, 2} };
    cout << formingMagicSquare(s) << "\n";

}