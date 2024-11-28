#include <iostream>
#include <vector>
#include <limits>
#include <stdlib.h> 

using std::cout;
using std::vector;

int calculateTotalDifference(vector<int> arr) {

    int totalDifference = 0;
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        totalDifference += std::abs(*it);

    return totalDifference;

}

vector<vector<int>> alterSquare(vector<vector<int>> s, int row, int column, int value) {

    s[row][column] = value;
    return s;

}

vector<int> squareDifferences(vector<vector<int>> s, int MAGIC_CONSTANT) {
    
    vector<int> differences;
    
    // ROWS
    for (int i = 0; i < s.size(); i++) {
        
        int rowSum = 0;
        for (int j = 0; j < s[0].size(); j++)
            rowSum += s[i][j];
        differences.push_back(MAGIC_CONSTANT - rowSum);

    }

    // LEFT TO RIGHT DIAGONAL
    int diagonalSum = 0;
    for (int i = 0, j = 0; i < s.size() && j < s[i].size(); i++, j++)
        diagonalSum += s[i][j];
    differences.push_back(MAGIC_CONSTANT - diagonalSum);


    diagonalSum = 0; // reset diagonal for the other diagonal calculation

    // COLUMNS
    for (int j = 0; j < s.size(); j++) {

        int columnSum = 0;
        for (int i = 0; i < s.size(); i++)
            columnSum += s[i][j];

        differences.push_back(MAGIC_CONSTANT - columnSum);
      
    }

    // RIGHT TO LEFT DIAGONAL
    for (int i = 0, j = s[i].size() - 1; i <= s.size() && j >= 0; i++, j--)
        diagonalSum += s[i][j];
    differences.push_back(MAGIC_CONSTANT - diagonalSum);
    
    return differences;
    
}

bool duplicate(vector<vector<int>> s, int value) {

    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < s[i].size(); j++)
            if (s[i][j] == value)
                return true;

    return false;

}

int bestValue(vector<vector<int>> s, int index, int & row, int & column, vector<int> & differences) {

    int value = -1;
    int minimumDifference = calculateTotalDifference(differences);
    for (int iterations = 0; iterations < s.size(); iterations++) {

        for (int k = 1; k <= 9; k++) {

            int currentDifference;
            if (0 <= index && index < s.size()) {

                currentDifference = calculateTotalDifference(squareDifferences(alterSquare(s, index, iterations, k), 15));

                if (currentDifference < minimumDifference || (currentDifference == minimumDifference && !duplicate(s, k))) {

                    minimumDifference = currentDifference;
                    value = k;
                    row = index;
                    column = iterations;

                }

            }
            else if (index == s.size())  {

                currentDifference = calculateTotalDifference(squareDifferences(alterSquare(s, iterations, iterations, k), 15));

                if (currentDifference < minimumDifference || (currentDifference == minimumDifference && !duplicate(s, k))) {

                    minimumDifference = currentDifference;
                    value = k;
                    row = iterations;
                    column = iterations;

                }

            }
            else if (s.size() < index && index < s.size() * 2) {

                currentDifference = calculateTotalDifference(squareDifferences(alterSquare(s, index % s.size() - 1, iterations, k), 15));

                if (currentDifference < minimumDifference || (currentDifference == minimumDifference && !duplicate(s, k))) {

                    minimumDifference = currentDifference;
                    value = k;
                    row = index % s.size() - 1;
                    column = iterations;

                }

            }
            else if (index == s.size() * 2) {

                currentDifference = calculateTotalDifference(squareDifferences(alterSquare(s, index % s.size(), iterations, k), 15));

                if (currentDifference < minimumDifference || (currentDifference == minimumDifference && !duplicate(s, k))) {

                    minimumDifference = currentDifference;
                    value = k;
                    row = index / s.size();
                    column = iterations;

                }

            }
            else {
                
                currentDifference = calculateTotalDifference(squareDifferences(alterSquare(s, iterations, s.size() - iterations - 1, k), 15));

                if (currentDifference < minimumDifference || (currentDifference == minimumDifference && !duplicate(s, k))) {

                    minimumDifference = currentDifference;
                    value = k;
                    row = iterations;
                    column = s.size() - iterations - 1;

                }

            }

        }

    }

    return value;

}

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) {
    
    const int MAGIC_CONSTANT = 15;
    vector<int> differences = squareDifferences(s, MAGIC_CONSTANT);

    int cost = 0;

    /*for (int sum : differences)
        cout << sum << " ";
    cout << "\n";*/

    int currentIndex = 0;
    while (calculateTotalDifference(differences) != 0) {

        if (differences[currentIndex] != 0) {

            int value, row, column = 0;
            
            value = bestValue(s, currentIndex, row, column, differences); // only works when analysing rows for now, the second argument needs a lil touching

            if (value != -1) {
                cost += abs(s[row][column] - value);
                s = alterSquare(s, row, column, value); // Alter matrix to match the recently made changes
                differences = squareDifferences(s, MAGIC_CONSTANT); // update 'differences' with the new matrix information
            }

            currentIndex++;

        }
        else 
            currentIndex++;

        //cout << currentIndex << "\n";

        for (int i = 0; i < s.size(); i++)
                for (int j = 0; j < s[i].size(); j++)
                    cout << s[i][j] << " ";
            cout << "\n";

        if (currentIndex == s.size() * s[0].size())
            currentIndex = 0;


    }

    return cost;

}

int main() {

    vector<vector<int>> s { {2, 9, 8}, {4, 2, 7}, {5, 6, 7} };
    cout << formingMagicSquare(s) << "\n";

}