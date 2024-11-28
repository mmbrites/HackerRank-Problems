vector<int> icecreamParlor(int m, vector<int> arr) {
    
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        
        if (arr[i] < m) {
            
            for (int j = i + 1; j < arr.size(); j++)
                if (arr[i] + arr[j] == m) {
                    result.push_back(i + 1);
                    result.push_back(j + 1);
                }
            
        }
        
    }
    
    return result;

}

int main() {


    
}