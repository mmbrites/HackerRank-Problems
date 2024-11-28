#include <iostream>
#include <string>

using std::cout;
using std::string;

int calculateShift(int k) {

    int realShift = k;
    while (realShift > 26)
        realShift -= 26;
    
    return realShift;

}

string caesarCipher(string s, int k) {

    int shift = calculateShift(k);
    
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        
        if ((*it) >= 'a' && (*it) <= 'z') {
            
            if ((*it) + shift > 'z')
                (*it) = (*it) + ('a' - 'z' - 1) + shift;
            else 
                (*it) += shift;
            
        }
        else if ((*it) >= 'A' && (*it) <= 'Z') {
            
            if ((*it) + shift > 'Z')
                (*it) = (*it) + ('A' - 'Z' - 1) + shift;
            else
                (*it) += shift;
            
        }
        
    }
    
    return s;

}

int main() {

    string s = "Hello_World!";
    cout << caesarCipher(s, 30) << "\n";

}