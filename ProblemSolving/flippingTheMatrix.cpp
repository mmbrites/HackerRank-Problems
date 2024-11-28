#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::max;

int maximumInMirrorRows(int row, int column, vector<vector<int>> & matrix) {
    
    int maximum = 0;
    int matrixSize = matrix.size();
    
    maximum = max(maximum, matrix[row][column]);
    maximum = max(maximum, matrix[row][matrixSize - 1 - column]);
    maximum = max(maximum, matrix[matrixSize - 1 - row][column]);
    maximum = max(maximum, matrix[matrixSize - 1 - row][matrixSize - 1 - column]);
        
    return maximum;
    
}

int flippingMatrix(vector<vector<int>> matrix) {
    
    int maximumSum = 0;
    for (int i = 0; i < matrix.size() / 2; i++)
        for (int j = 0; j < matrix.size() / 2; j++)
            maximumSum += maximumInMirrorRows(i, j, matrix);
        
    return maximumSum;

}

int main() {

    vector<vector<int>> matrix = { {112, 42}, {56, 125}};
    cout << flippingMatrix(matrix) << "\n";

}