#include <iostream>
#include <string>
#include <math.h>

using std::cout;
using std::string;
using std::min;

int anagram(string s) {

    // So, from my understanding: if s.size() % 2 != 0, then the result is '-1'
    
    if (s.size() % 2 != 0)
        return -1;
        
    // Testing on paper first...
    
    int sSize = s.size();
    string firstString = s.substr(0, sSize / 2);
    string secondString = s.substr(sSize / 2, sSize / 2);
    
    int lettersFirstString[26];
    int lettersSecondString[26];

    for (int i = 0; i < 26; i++) {

        lettersFirstString[i] = 0;
        lettersSecondString[i] = 0;
    
    }
    
    for (int i = 0; i < sSize / 2; i++) {
        
        lettersFirstString[firstString[i] - 'a']++;
        lettersSecondString[secondString[i] - 'a']++;
    
    }
    
    int necessaryChanges = sSize / 2;
    for (int i = 0; i < 26; i++)
        if (lettersFirstString[i] > 0 && lettersSecondString[i] > 0)
            necessaryChanges -= min(lettersFirstString[i], lettersSecondString[i]);

    return necessaryChanges;

}

int main() {

    string s = "xaxbbbxx";
    cout << anagram(s) << "\n";

}