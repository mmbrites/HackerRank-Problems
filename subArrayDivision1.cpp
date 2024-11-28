#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int birthday(vector<int> s, int d, int m) {
    
    int ways = 0;
    for (int i = 0; i < s.size() - m + 1; i++) {
        
        int sum = 0;
        for (int j = i; j < i + m; j++)
            sum += s[j];
            
        cout << sum << "\n";
            
        if (sum == d)
            ways++;
        
    }
    
    return ways;

}

int main() {

    vector<int> s = {1, 2, 1, 3, 2};
    int d = 3;
    int m = 2;

    cout << birthday(s, d, m) << "\n";

}