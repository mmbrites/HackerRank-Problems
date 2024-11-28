void minimumBribes(vector<int> q) {
    
    int bribes = 0;
    
    for (int i = 1; i < q.size(); i++) {
        
        for (int j = i; j >= 0 && q[j] < q[j - 1]; j--) {
            
            if (q[j - 1] - (j - 1 + 1) > 2) {
                cout << "Too chaotic\n";
                return;
            }
            
            int temp = q[j - 1];
            q[j - 1] = q[j];
            q[j] = temp;
            bribes++;
            
        }
        
    }
    
    cout << bribes << "\n";

}

int main() {

    
}