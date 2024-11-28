#include <iostream>
#include <string>

using std::cout;
using std::string;


// Not an optimal solution, will search
bool palindrome(string s) {
    
    int middlePosition = s.size() / 2;
        
    string firstString;
    string secondString;
    if (s.size() % 2 == 0) {
        
        firstString = s.substr(0, middlePosition);
        secondString = s.substr(middlePosition, middlePosition);
        
        cout << firstString << " " << secondString << "\n";

    }
    else {
        
        firstString = s.substr(0, middlePosition);
        secondString = s.substr(middlePosition + 1, middlePosition);
        
    }

    // REVERSE ITERATOR TO CREATE OTHER STRING
    string toCompare;
    for (string::reverse_iterator it = firstString.rbegin(); it != firstString.rend(); ++it)
        toCompare += *it;
    
    return toCompare == secondString;
    
}

int palindromeIndex(string s) {
    
    // 1st: Verify if 's' is a palindrome
    if (palindrome(s)) {
        cout << "Does it enter here?\n";
        return -1;
    }
    
    // 2nd: Cycle through 's' to know if, by removing a character, it is possible to obtain a palindrome
    for (int i = 0; i < s.size(); i++) {
        
        //if (i == 0) 
        //    if (palindrome(s.substr()))
        
        if (i == 0) {
            
            string firstString = s.substr(0, i);
            string secondString = s.substr(i + 1, s.size() - 1);
            
            if (palindrome(firstString + secondString))
                return 0;
            
        }
        else if (i == s.size() - 1) {
            
            if (palindrome(s.substr(0, i)))
                return i;
            
        }
        else {
            
            string firstString = s.substr(0, i);
            string secondString = s.substr(i + 1, s.size() - i);
            
            if (palindrome(firstString + secondString))
                return i;
        
        }
        
    }
    
    return -1;

}

int main() {

    cout << palindromeIndex("bcbc") << "\n";

}