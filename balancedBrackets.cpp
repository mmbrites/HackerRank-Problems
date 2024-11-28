#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::ofstream;

bool openingBracket(char c) {
    return c == '{' || c == '[' || c == '(';
}

bool closingBracket(char c) {
    return c == '}' || c == ']' || c == ')';
}

bool matchesWithLastBracket(char opening, char closing) {
    
    switch (opening) {
    
        case '{': return closing == '}';
        case '[': return closing == ']';
        case '(': return closing == ')';
        default: return false;
        
    }
    
}

bool recursiveBalancedBrackets(string s, vector<char> & vec) {
    
    if (s.size() == 0) {

        if (vec.size() == 0)
            return true;
        return false;

    }
    
    if (openingBracket(s[0])) {
        
        vec.push_back(s[0]);
        return true && recursiveBalancedBrackets(s.substr(1, s.size() - 1), vec);
        
    }
    else {
        
        if (vec.size() != 0 && matchesWithLastBracket(vec.back(), s[0])) {
            
            vec.pop_back();
            return true && recursiveBalancedBrackets(s.substr(1, s.size() - 1), vec);
        
        }
        
        return false;
        
    }
    
}

string isBalanced(string s) {
    
    vector<char> vec;
    if (recursiveBalancedBrackets(s, vec))
        return "YES";
    return "NO";

}

int main() {

    int queries;
    int currentQuery = 0;
    cin >> queries;

    ofstream outputFile("output.txt");
    
    while (currentQuery < queries) {

        string s;
        cin >> s;

        cout << isBalanced(s) << "\n";
        currentQuery++;
    
    }

    outputFile.close();

}