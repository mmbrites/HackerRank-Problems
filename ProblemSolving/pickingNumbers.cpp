int pickingNumbers(vector<int> a) {
    
    sort(a.begin(), a.end(), [] (const int y, const int z) -> bool {
        return y < z;
    });
    
    int maximumLength = 1;
    int anchor = a[0];
    int currentLength = 1;
    for (int i = 1; i < a.size(); i++) {
        
        if (anchor + 1 < a[i]) {
            
            maximumLength = max(maximumLength, currentLength);
            anchor = a[i];
            currentLength = 1;
            
        }
        else
            currentLength++;
        
    }
    
    if (currentLength == a.size())
        return currentLength;
    
    return maximumLength;

}

int main() {



}