string balancedSums(vector<int> arr) {
    
    int totalSum = 0;
    for (int i = 0; i < arr.size(); i++)
        totalSum += arr[i];
    
    int leftSideSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        
        if (i != 0)
            leftSideSum += arr[i - 1];
        
        if (leftSideSum == totalSum - arr[i] - leftSideSum)
            return "YES";
    
    }
        
    return "NO";

}

int main() {


    
}