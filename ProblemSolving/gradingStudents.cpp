#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> gradingStudents(vector<int> grades) {
    
    vector<int> roundedGrades;
    for (vector<int>::iterator it = grades.begin(); it != grades.end(); ++it) {
        
        if ((*it) < 38 || ((*it) % 5 == 0))
            roundedGrades.push_back(*it);
        else {
            
            int multiplier = ceil((float) *it / 5);
            cout << multiplier << "\n";
            int upperFiveMultiple = multiplier * 5;

            if (*it > upperFiveMultiple - 3)
                roundedGrades.push_back(multiplier * 5);
            else
                roundedGrades.push_back(*it);
            
        }
        
    }
    
    return roundedGrades;

}


int main() {

    vector<int> grades = {4, 73, 67, 38, 33};
    grades = gradingStudents(grades);
    for (int i : grades)
        cout << i << " ";
    cout << "\n";

}