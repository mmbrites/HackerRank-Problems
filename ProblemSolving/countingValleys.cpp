#include <iostream>
#include <string>

using std::cout;
using std::string;

// THE ONLY THING THAT MATTERS IS THE SEA LEVEL :)
int countingValleys(int steps, string path) {
    
    int currentLevel = 0;
    int valleys = 0;
    bool valley = false;
    
    for (int step = 0; step < steps; step++) {
        
        if (path[step] == 'D')
            currentLevel--;
        else if (path[step] == 'U')
            currentLevel++;
            
        if (path[step] == 'U' && currentLevel == 0)
            valleys++;
        
    }
    
    return valleys;

}

int main() {

    cout << countingValleys(100, "DUDUUUUUUUUDUDDUUDUUDDDUUDDDDDUUDUUUUDDDUUUUUUUDDUDUDUUUDDDDUUDDDUDDDDUUDDUDDUUUDUUUDUUDUDUDDDDDDDDD") << "\n";

}