#include <iostream>
#include <string>

using std::cout;
using std::string;

string isValid(string s) {
    
    if (s.size() == 1)
        return "YES";
    
    int letters[26];
    for (int i = 0; i < 26; i++)
        letters[i] = 0;
    
    for (int i = 0; i < s.size(); i++)
        letters[s[i] - 'a']++;
        
    int benchmark;
    bool toRemove = false;
    
    if (letters[0] == letters[1])
        benchmark = letters[0];
    else if (letters[0] == letters[1] + 1) {
        benchmark = letters[1];
        toRemove = true;
    }
    else if (letters[0] + 1 == letters[1]) {
        benchmark = letters[0];
        toRemove = true;
    }
    else
        return "NO";
      
    for (int i = 0; i < 26; i++) {
        
        if (letters[i] != 0 && letters[i] != benchmark) {
            
            if (!toRemove && (letters[i] == benchmark + 1 || letters[i] == 1))
                toRemove = true;
            else
                return "NO";
            
        }
        
    }
    
    return "YES";

}

int main() {

    string s = "ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd";
    cout << isValid(s) << "\n";

}