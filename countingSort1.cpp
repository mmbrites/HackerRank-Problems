vector<int> countingSort(vector<int> arr) {
    
    vector<int> histogram;
    histogram.reserve(100);
    
    for (int i = 0; i < 100; i++)
        histogram.push_back(0);
        
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        histogram[*it]++;
        
    return histogram;

}

int main() {
    
}