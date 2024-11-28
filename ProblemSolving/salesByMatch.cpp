int sockMerchant(int n, vector<int> ar) {
    
    sort(ar.begin(), ar.end(), [](const int a, const int b) -> int {
        return a < b;
    });
    
    int countUntilChange = 0;
    int currentSockColor = ar[0];
    int totalSocks = 0;
    
    for (vector<int>::iterator it = ar.begin(); it != ar.end(); ++it) {
        
        if ((*it) == currentSockColor)
            countUntilChange++;
        else {
            totalSocks += countUntilChange / 2;
            currentSockColor = (*it);
            countUntilChange = 1; 
        }
        
    }
    
    totalSocks += countUntilChange / 2;
    
    return totalSocks;

}

int main() {
    
}