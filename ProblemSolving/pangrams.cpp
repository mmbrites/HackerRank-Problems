string pangrams(string s) {
    
    bool letters[26];
    for (int i = 0; i < 26; i++)
        letters[i] = false;
        
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        
        if ((*it) >= 'a' && (*it) <= 'z')
            letters[(*it) - 'a'] = true;
        else if ((*it) >= 'A' && (*it) <= 'Z')
            letters[(*it) - 'A'] = true;
        
    }
    
    for (int i = 0; i < 26; i++)
        if (letters[i] == false)
            return "not pangram";

    return "pangram";

}

int main() {
    
}