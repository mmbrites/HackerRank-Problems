#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;

int leaderboardRanks(vector<int> leaderboard) {

    vector<int>::iterator end = std::unique(leaderboard.begin(), leaderboard.end());
    int lbRanks = 0;
    for (vector<int>::iterator it = leaderboard.begin(); it != end; ++it)
        lbRanks++;

    return lbRanks;

}

// Full points solution :)
vector<int> climbingLeaderboard(vector<int> leaderboard, vector<int> playerScores) {

    vector<int> results;
    results.reserve(playerScores.size());

    int lbRanks = leaderboardRanks(leaderboard);
    vector<int>::const_reverse_iterator revItCurrent = leaderboard.crbegin();
    vector<int>::const_reverse_iterator revItNext = leaderboard.crbegin();
    ++revItNext;
    
    int currentRank = 1;

    for (int i = 0; i < playerScores.size(); i++) {

        while (revItCurrent != leaderboard.crend()) {

            if (playerScores[i] < (*revItCurrent)) {
                results.push_back(lbRanks - currentRank + 2);
                break;
            }
            else if (playerScores[i] == (*revItCurrent)) {
                results.push_back(lbRanks - currentRank + 1);
                break;
            }
            else if (currentRank == lbRanks) {
                results.push_back(1);
                break;
            }

            if ((*revItCurrent) != (*revItNext))
                currentRank++;

            ++revItCurrent;
            ++revItNext;

        }

    }

    return results;

}

int main() {

    vector<int> leaderboard = {100, 90, 90, 80, 75, 60};
    vector<int> playerScores = {50, 65, 77, 90, 102};

    vector<int> results = climbingLeaderboard(leaderboard, playerScores);
    for (vector<int>::iterator it = results.begin(); it != results.end(); ++it)
        cout << *it << "\n";

}