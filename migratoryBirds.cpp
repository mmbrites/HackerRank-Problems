#include <iostream>
#include <vector>

using namespace std;

int migratoryBirds(vector<int> arr) {
    
    vector<int> birdHistogram; // to avoid sorting the array :)
    birdHistogram.reserve(5); // Bird types are 1 to 5
    
    for (int i = 0; i < 5; i++)
        birdHistogram.push_back(0);
    
    for (int i : arr)
        birdHistogram[i - 1]++;
        
    int birdType = 1;
    int maxOccurrences = birdHistogram[0];
    for (int i = 1; i < birdHistogram.size(); i++)
        if (maxOccurrences < birdHistogram[i]) {
            birdType = i + 1;
            maxOccurrences = birdHistogram[i];
        }
        
    return birdType;

}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4};
    cout << migratoryBirds(arr) << "\n";

}