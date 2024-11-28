#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::string;

void explosions(vector<string> & nextToExplode, vector<string> & grid) {

    for (int i = 0; i < nextToExplode.size(); i++) {

        for (int j = 0; j < nextToExplode[i].size(); j++) {

            if (nextToExplode[i][j] == 'O') {

                grid[i][j] = '.';
                nextToExplode[i][j] = '.';
                if (i > 0) {
                    grid[i - 1][j] = '.';
                    nextToExplode[i - 1][j] = '.';
                }
                if (j > 0) {
                    grid[i][j - 1] = '.';
                    nextToExplode[i][j - 1] = '.';
                }
                if (i < nextToExplode.size() - 1)
                    grid[i + 1][j] = '.';
                if (j < nextToExplode[i].size() - 1)
                    grid[i][j + 1] = '.';

            }
            else if (grid[i][j] == 'O')
                nextToExplode[i][j] = 'O';

        }

    }

}

// I am proud of this solution, but this is not what HackerRank wants
vector<string> bombeMan(int n, vector<string> grid) {
    
    int secondsPassed = 1;
    vector<string> nextToExplode = grid; // 1st bombs to explode are already on the grid

    string fullBombRow = "";
    for (int j = 0; j < grid[0].size(); j++)
        fullBombRow += "O";
    
    while (secondsPassed < n) {
        
        secondsPassed++;
        
        // PLANTS BOMBS
        if (secondsPassed % 2 == 0)
            for (int i = 0; i < grid.size(); i++)
                grid[i] = fullBombRow;
        // BOMBS EXPLODE
        else 
            explosions(nextToExplode, grid);
        
    }
    
    return grid;

}

vector<string> bomberMan(int n, vector<string> grid) {
    
    if (n % 2 == 0) {

        string fullBombRow = "";
        for (int j = 0; j < grid[0].size(); j++)
            fullBombRow += "O";
        for (int i = 0; i < grid.size(); i++)
            grid[i] = fullBombRow;

    }
    else if (n < 3)
        return grid;
    else if ((n - 3) % 4 == 0) {

        vector<string> toExplode = grid;
        string fullBombRow = "";
        for (int j = 0; j < grid[0].size(); j++)
            fullBombRow += "O";
        for (int i = 0; i < grid.size(); i++)
            grid[i] = fullBombRow;

        explosions(toExplode, grid);

    }
    else if ((n - 5) %  4 == 0) {

        vector<string> toExplode = grid;
        string fullBombRow = "";
        for (int j = 0; j < grid[0].size(); j++)
            fullBombRow += "O";
        for (int i = 0; i < grid.size(); i++)
            grid[i] = fullBombRow;

        explosions(toExplode, grid);
        for (int i = 0; i < grid.size(); i++)
            grid[i] = fullBombRow;
        explosions(toExplode, grid);

    }

    
    return grid;

}

int main() {

    vector<string> grid = {".......", "...O.O.", "....O..", "..O....", "OO...OO", "OO.O..."};
    vector<string> result = bomberMan(5, grid);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";

}