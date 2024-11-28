int maximum(vector<int> arr) {
    
    int maximum = arr[0];
    for (int i = 1; i < arr.size(); i++)
        maximum = max(arr[i], maximum);
    
    return maximum;
    
}

/*
 * Complete the 'hurdleRace' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY height
 */

int hurdleRace(int k, vector<int> height) {
    
    int maxHurdleHeight = maximum(height);
    if (k > maxHurdleHeight)
        return 0;
    return maxHurdleHeight - k;

}

int main() {
    
}