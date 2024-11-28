#include <iostream>

using std::cout;

int inbounds(int startPositionHouse, int endPositionHouse, int treePosition, vector<int> & fruitDistance) {
    
    int countInbounds = 0;
    for (int distance : fruitDistance) {
        
        int fruitPosition = treePosition + distance;
        if (startPositionHouse <= fruitPosition && fruitPosition <= endPositionHouse)
            countInbounds++;
        
    }
    
    return countInbounds;
    
}

/*
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    
    cout << inbounds(s, t, a, apples) << "\n";
    cout << inbounds(s, t, b, oranges) << "\n";

}

int main() {



}