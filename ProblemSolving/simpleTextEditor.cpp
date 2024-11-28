#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

enum {APPEND = 1, DELETE, PRINT, UNDO};

void append(string & s, string toAppend) {
    s += toAppend;
}

void deleteChars(string & s, int quantity) {
    s = s.substr(0, s.size() - quantity);
}

void printChar(string s, int index) {
    cout << s[index - 1] << "\n";
}

int main() {

    int currentQuery = 0;
    int queries;
    cin >> queries;
    cin.get(); // Ignore "new line"
    
    string s = "";
    vector<string> stringState;
    stringState.push_back(s);

    while (currentQuery < queries) {

        int queryType;
        string appendArgument = "";
        int argument = 0;

        cin >> queryType;

        switch (queryType) {

            case APPEND: 
                cin >> appendArgument;
                append(s, appendArgument);
                stringState.push_back(s);
                break;

            case DELETE:
                cin >> argument;
                deleteChars(s, argument);
                stringState.push_back(s);
                break;

            case PRINT:
                cin >> argument;
                printChar(s, argument);
                break;
            
            case UNDO:
                stringState.pop_back();
                s = stringState.back();
                break;

            default:
                break;

        }

        currentQuery++;

    }

}