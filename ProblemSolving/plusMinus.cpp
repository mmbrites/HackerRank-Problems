/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    
    int positive = 0;
    int neutral = 0;
    int negative = 0;
    
    for (int i : arr) {
        if (i > 0)
            positive++;
        else if (i == 0)
            neutral++;
        else
            negative++;
    }
     
    cout << std::fixed << std::setprecision(6);
    cout << (float) positive / arr.size() << "\n"; 
    cout << (float) negative / arr.size() << "\n"; 
    cout << (float) neutral / arr.size() << "\n"; 

}

int main() {

    
}