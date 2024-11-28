#include <iostream>
#include <vector>

using namespace std;

void miniMaxSum(vector<int> arr) {
    
    // This way, we can obtain the max and min values easily since we know where the elements we want are
    for (int i = 1; i < arr.size(); i++) {
        
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            
            int temporary = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temporary;
            
        }
        
    }
    
    // Output could be bigger than a 32-bit integer
    long minimumSum = 0;
    long maximumSum = 0;
    for (int i = 0; i < 4; i++)
        minimumSum += arr[i];
    for (int i = arr.size() - 1; i > arr.size() - 5; i--)
        maximumSum += arr[i];
        
    cout << minimumSum << " " << maximumSum << "\n";

}

int main() {

    vector<int> arr = {256741038, 623958417, 467905213, 714532089, 938071625};
    miniMaxSum(arr);

}