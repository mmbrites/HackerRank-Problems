// The exercise said arr had an odd number of elements
int findMedian(vector<int> arr) {
    
    sort(arr.begin(), arr.end(), [] (const int a, const int b) -> bool {
       return a < b; 
    });
    return arr[arr.size() / 2];

}

int main() {

}