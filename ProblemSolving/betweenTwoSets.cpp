#include <iostream>
#include <vector>

using std::cout;
using std::vector;

bool elementsAreFactors(vector<int> & a, int i) {
    
    for (int j = 0; j < a.size(); j++)
        if (i % a[j]) 
            return false;
    
    return true;
    
}

bool intIsFactorOfAll(vector<int> & b, int i) {
    
    for (int j = 0; j < b.size(); j++)
        if (b[j] % i)
            return false;
    
    return true;
    
}

int getTotalX(vector<int> a, vector<int> b) {

    // Considering both arrays are sorted from the get go, we can do a little cycle
    int count = 0;
    for (int i = a[a.size() - 1]; i <= b[0]; i++) {
        cout << i << "\n";
        if (elementsAreFactors(a, i) && intIsFactorOfAll(b, i))
            count++;
    }
    return count;

}

int main() {

    vector<int> a = {2, 4};
    vector<int> b = {16, 32, 96};
    cout << getTotalX(a, b) << "\n";

}