#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    
    // Declare a 2D array and initialise empty arrays
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++) {

        vector<int> arr;
        matrix.push_back(arr);
    
    }
            
    // Declare and initialise integer
    int lastAnswer = 0;
    
    // Declare array that stores the answers to queries of type '2'
    vector<int> answers;
    
    // Main cycle that answers to the 'queries'
    for (int i = 0; i < queries.size(); i++) {
        
        int idx = (queries[i][1] ^ lastAnswer) % n;
        
        if (queries[i][0] == 1)
            matrix[idx].push_back(queries[i][2]);
        else if (queries[i][0] == 2) {
            
            lastAnswer = matrix[idx][queries[i][2] % matrix[idx].size()];
            answers.push_back(lastAnswer);
            
        }
        
    }
    
    return answers;

}

int main() {

    vector<vector<int>> queries = { {1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}};
    vector<int> answers = dynamicArray(2, queries);
    for (int i : answers)
        cout << i << " ";
    cout << "\n";

}