int lonelyinteger(vector<int> a) {
    
    sort(a.begin(), a.end(), [] (const int b, const int c) -> bool {
       return b < c; 
    });
    
    for (int i = 0; i < a.size(); i += 2)
        if (a[i] != a[i + 1])
            return a[i];
            
    return -1;

}

int main() {

}