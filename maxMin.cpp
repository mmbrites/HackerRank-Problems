#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::sort;
using std::min;
using std::max;

int maxMin(int k, vector<int> arr) {

    sort(arr.begin(), arr.end(), [] (const int a, const int b) -> bool {
        return a < b;
    });

    vector<int> unfairness;
    unfairness.reserve(arr.size() - 1);

    for (int i = 0; i < arr.size() - k + 1; i++)
        unfairness.push_back(arr[i + k - 1] - arr[i]);

    sort(unfairness.begin(), unfairness.end(), [] (const int a, const int b) -> bool {
        return a < b;
    });

    return unfairness[0];

}

int main() {

    vector<int> arr = {100,200,300,350,400,401,402};
    cout << maxMin(3, arr) << "\n";

}