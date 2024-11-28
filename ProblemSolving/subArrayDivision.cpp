int birthday(vector<int> s, int d, int m) {
    
    int segments = 0;
    for (int i = 0; i < s.size(); i++) {
        
        int sum = 0;
        for (int j = i; j < i + m; j++)
            sum += s[j];
            
        if (sum == d)
            segments++;
        
    }
    
    return segments;

}

int main() {
    
}