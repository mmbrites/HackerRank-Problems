#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using std::cout;
using std::vector;
using std::min;

int initialHeight(vector<int> & cylinder) {
    
    int height = 0;
    for (int i = 0; i < cylinder.size(); i++)
        height += cylinder[i];
    
    return height;
    
}

int minimumElement(vector<int> & cylinder) {
    
    int minimum = INT_MAX;
    for (int i = 0; i < cylinder.size(); i++)
        minimum = min(minimum, cylinder[i]);
    
    return minimum;
    
}

vector<int> possibleHeights(vector<int> & h, int startingHeight, int minimumElementHeight) {
    
    int sum = 0;
    for (int i = 0; i < h.size(); i++)
        sum += h[i];
    
    vector<int> heights;
    if (sum <= startingHeight && sum >= minimumElementHeight)
        heights.push_back(sum);
        
    for (int i = 0; i < h.size(); i++) {
        
        sum -= h[i];
        
        if (sum <= startingHeight && sum >= minimumElementHeight)
            heights.push_back(sum);
        
    }
    
    return heights;
    
}

vector<int> maximumHeight(vector<int> & h1Heights, vector<int> & h2Heights) {
    
    int h1Index = 0;
    int h2Index = 0;
    
    vector<int> commonHeights;
    
    while (h1Index < h1Heights.size() && h2Index < h2Heights.size()) {

        
        if (h1Heights[h1Index] > h2Heights[h2Index])
            h1Index++;
        else if (h1Heights[h1Index] < h2Heights[h2Index])
            h2Index++;
        else {
        
            commonHeights.push_back(h1Heights[h1Index]);
            h1Index++;
            h2Index++;
            
        }
        
    }
    
    return commonHeights;
    
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {

    int startingHeight = min(initialHeight(h1), initialHeight(h2));
    startingHeight = min(startingHeight, initialHeight(h3));
    
    int minimumElementHeight = min(minimumElement(h1), minimumElement(h2));
    minimumElementHeight = min(minimumElementHeight, minimumElement(h3));

    vector<int> h1Heights = possibleHeights(h1, startingHeight, minimumElementHeight);
    vector<int> h2Heights = possibleHeights(h2, startingHeight, minimumElementHeight);
    vector<int> h3Heights = possibleHeights(h3, startingHeight, minimumElementHeight);    
    
    vector<int> temp = maximumHeight(h1Heights, h2Heights);
    vector<int> hasMax = maximumHeight(temp, h3Heights);

    if (hasMax.empty())
        return 0;
    
    return hasMax[0];

}

int main() {

    vector<int> h1 = {1, 1, 1, 1, 2};
    vector<int> h2 = {3, 7};
    vector<int> h3 = {1, 3, 1};

    cout << equalStacks(h1, h2, h3) << "\n";

}