#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::vector;
using std::string;
using std::sort;

string gridChallenge(vector<string> grid) {

    for (int i = 0; i < grid.size(); i++)
        sort(grid[i].begin(), grid[i].end(), [] (const char a, const char b) -> bool { return a < b; });

    for (int j = 0; j < grid[0].size(); j++)
        for (int i = 0; i < grid.size() - 1; i++)
            if (!(grid[i][j] <= grid[i + 1][j]))
                return "NO";

    return "YES";

}

int main() {

    vector<string> grid = {"ebacd", "fghij", "olmkn", "trpqs", "xywuv"};
    cout << gridChallenge(grid) << "\n";

}