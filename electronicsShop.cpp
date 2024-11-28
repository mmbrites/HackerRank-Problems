int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    
    int max = 0; // could just be '-1' to avoid the check after the double cycle :)
    for (int i = 0; i < keyboards.size(); i++)
        for (int j = 0; j < drives.size(); j++)
            if ((keyboards[i] + drives[j]) > max && (keyboards[i] + drives[j]) <= b)
                max = keyboards[i] + drives[j];
    
    if (max == 0)
        return -1;            
    
    return max;

}

int main() {

}