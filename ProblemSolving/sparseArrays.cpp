vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    vector<int> queryOccurences;
    queryOccurences.reserve(queries.size());
    
    for (int i = 0; i < queries.size(); i++)
        queryOccurences.push_back(0);
    
    for (int i = 0; i < queries.size(); i++) {
        
        for (int j = 0; j < strings.size(); j++) {
            
            if (queries[i] == strings[j])
                queryOccurences[i]++;
            
        }
        
    }
    
    return queryOccurences;

}

// O(3.n) solution :)
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    vector<int> queryOccurrences;
    queryOccurrences.reserve(queries.size());
    
    for (int i = 0; i < queries.size(); i++)
        queryOccurrences.push_back(0);
    
    map<string, int> stringOccurrences;
    for (string s : strings) {
        
        if (stringOccurrences.find(s) == stringOccurrences.end())
            stringOccurrences.insert(pair<string, int>(s, 1));
        else
            stringOccurrences[s] = stringOccurrences.find(s)->second + 1;
        
    }
    
    for (int i = 0; i < queries.size(); i++) {
        
        if (stringOccurrences.find(queries[i]) != stringOccurrences.end())
            queryOccurrences[i] = stringOccurrences.find(queries[i])->second;
        
    }
    
    return queryOccurrences;

}

int main() {

}