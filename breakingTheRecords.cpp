vector<int> breakingRecords(vector<int> scores) {
    
    vector<int> recordBreakings = {0, 0};
    
    int minimum = scores[0];
    int maximum = scores[0];
    for (int i = 1; i < scores.size(); i++) {
        
        if (scores[i] > maximum) {
            recordBreakings[0]++;
            maximum = scores[i];
        }
        else if (scores[i] < minimum) {
            recordBreakings[1]++;
            minimum = scores[i];
        }
        
    }
    
    return recordBreakings;

}

int main() {



}