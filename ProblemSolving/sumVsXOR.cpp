#include <iostream>
#include <math.h>

using std::cout;
using std::log2;
using std::pow;

long sumXor(long n) {
    
    string number = std::bitset<64>(n).to_string(); // transforms long into a 64-bit binary
    
    int unsetBits = 0;
    bool startCounting = false;
    for (int i = 0; i < number.size(); i++) {
        
        if (number[i] == '1') // without this it would count the '0's to the left of the number
            startCounting = true;
        else if (startCounting && number[i] == '0')
            unsetBits++;
        
    }
    
    return 1L << unsetBits;

}

int main() {

    cout << sumXor(35) << "\n";

}