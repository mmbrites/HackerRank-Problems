int diagonalDifference(vector<vector<int>> arr) {
    
    int diagonalOne = 0;
    int diagonalTwo = 0;
    
    for (int i = 0, j = 0; i < arr.size() && j < arr[i].size(); i++, j++)
        diagonalOne += arr[i][j];
        
    for (int i = 0, j = arr.size() - 1; i < arr.size() && j >= 0; i++, j--)
        diagonalTwo += arr[i][j];
        
    return abs(diagonalOne - diagonalTwo);

}

int main() {

    
}