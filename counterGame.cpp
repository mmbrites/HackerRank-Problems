#include <iostream>
#include <string>
#include <math.h>

using std::cout;
using std::string;
using std::sqrt;
using std::pow;

string counterGame(long n) {
    
    int plays = 0;
    
    while (n != 1) {
        
        double power = log2(n);
        double decimalCases = power - int(power);
        
        if (decimalCases == 0)
            n /= 2;
        else
            n -= pow(2, int(power));
     
        plays++;
        
    }

    cout << plays << "\n";
    
    if (plays % 2)
        return "Louise";
    return "Richard";

}

int main() {

    cout << counterGame(35) << "\n";

}