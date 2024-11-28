#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout;
using std::vector;
using std::sort;
using std::string;

string twoArrays(int k, vector<int> A, vector<int> B) {
    
    sort(A.begin(), A.end(), [] (const int a, const int b) -> bool {
       return a < b; 
    });
     sort(B.begin(), B.end(), [] (const int a, const int b) -> bool {
       return a < b; 
    });

    bool selected[B.size()];

    for (int i = 0; i < B.size(); i++)
        selected[i] = false;

    for (int a : A) {

        bool hasPermutation = false;
        for (int i = 0; i < B.size(); i++) {

            if (a + B[i] >= k && !selected[i]) {
                selected[i] = true;
                hasPermutation = true;
                break;
            }

        }

        if (!hasPermutation)
            return "NO"; // means that there is an element from 'A' that does have a pair that can clear 'k'

    }

    return "YES";

}

int main() {

    vector<int> A {3, 6, 8, 5, 9, 9, 4, 8, 4, 7}; 
    vector<int> B {5, 1, 0, 1, 6, 4, 1, 7, 4, 3};
    int k = 9;

    cout << twoArrays(k, A, B) << "\n";

}