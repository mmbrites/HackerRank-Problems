#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    
    vector<int> results;
    results.reserve(2);
    
    results.push_back(0);
    results.push_back(0);
    
    for (int i = 0; i < a.size(); i++) {
     
        if (a[i] > b[i])
            results[0]++;
        else if (a[i] < b[i])
            results[1]++;
        
    }
    
    return results;

}

int main() {

    vector<int> a {0, 1, 2};
    vector<int> b {2, 0, 1};

    vector<int> result = compareTriplets(a, b);

    for (int i : result)
        cout << i << "\n";

}