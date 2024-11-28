int divisibleSumPairs(int n, int k, vector<int> ar) {

    int count = 0;
    for (int i = 0; i < ar.size() - 1; i++) {
        
        for (int j = i + 1; j < ar.size(); j++) {
            
            if ((ar[i] + ar[j]) % k == 0)
                count++;
        }
        
    }
    
    return count;

}

// OPTIMAL SOLUTION
int divisibleSumPairs(int n, int k, vector<int> ar) {

    map<int, int> mp;
    for (int i = 0; i < ar.size(); i++)
        mp[ar[i] % k]++; // Map is filled with occurences of (ar[i] % k), meaning, each key of the map is a remainder and the correspondent values are occurences
    
    int result = 0;
    // The cycle only goes until k/2 because the 'else' already considers the later portions of the map, and the exercise considers pair (x, y) == (y, x) true
    for (int i = 0; i <= k/2; i++) {
        
        // IF THE REMAINDER IS 0 OR THE REMAINDER IS HALF OF THE DIVISOR - THEY SHARE THE SAME CONDITION BECAUSE DUE TO PAIRING, THEIR SUM WILL BE A NUMBER WHICH, WHEN % K = 0.
        if (i == 0 || i * 2 == k)
            result += (mp[i] * (mp[i] - 1)) / 2; // AS SAID PREVIOUSLY, PAIRS (x, y) and (y, x) are equal, therefore, we need to divide by two in order to not count 1 pair as 2 
        else 
            result += mp[i] * mp[k - i]; // mp[k - i] corresponds to the complement, which allow the sum between those numbers to % k = 0!

    }

    return result;

}

int main() {



}