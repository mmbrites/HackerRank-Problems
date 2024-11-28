#include <iostream>
#include <vector>
#include <thread>

using std::cout;
using std::vector;
using std::thread;

void mainClimbingLeaderboard(vector<int> ranked, vector<int> player, vector<int> & results) {

    //vector<int> playerRanks;
    //playerRanks.reserve(player.size());

    for (int i = 0; i < player.size(); i++) {

        for (int j = 0; j < ranked.size(); j++) {

            if ((j == 0 && player[i] >= ranked[j]) || (player[i] == ranked[j])) {

                results.push_back(currentRank);
                break;

            }
            else if (j == ranked.size() - 1) {

                results.push_back(currentRank + 1);
                break; // Needs 'break' due to the next condition :)
            
            }
            else if ((ranked[j] > player[i]) && (player[i] > ranked[j + 1])) {

                results.push_back(currentRank + 1);
                break;

            }

            if (ranked[j] != ranked[j + 1])
                currentRank++;

        }

    }

    //results = playerRanks;
    //return playerRanks;

}

vector<int> climbingLeaderboard(vector<int> leaderboard, vector<int> playerScores) {

    unsigned int const MINIMUM_PER_THREAD = 100;
    unsigned int const MAX_THREADS = (playerScores.size() + MINIMUM_PER_THREAD - 1) / MINIMUM_PER_THREAD;
    unsigned int const HARDWARE_THREADS = std::thread::hardware_concurrency();
    unsigned int const NUMBER_OF_THREADS = std::min(HARDWARE_THREADS != 0 ? HARDWARE_THREADS : 4, MAX_THREADS);
    unsigned int const BLOCK_SIZE = playerScores.size() / NUMBER_OF_THREADS;

    vector<vector<int>> results(NUMBER_OF_THREADS);
    vector<thread> threads(NUMBER_OF_THREADS - 1);

    vector<int>::iterator blockStart = playerScores.begin();
    for (unsigned int i = 0; i < NUMBER_OF_THREADS - 1; i++) {

        vector<int>::iterator blockEnd = blockStart;
        std::advance(blockEnd, BLOCK_SIZE);
        vector<int> playerScoresSegment(blockStart, blockEnd);
        threads[i] = thread(mainClimbingLeaderboard, leaderboard, playerScoresSegment, std::ref(results[i]));
        blockStart = blockEnd;

    }
    
    vector<int> mainThreadWork(blockStart, playerScores.end());
    mainClimbingLeaderboard(leaderboard, mainThreadWork, results[NUMBER_OF_THREADS - 1]);

    for (thread& t : threads)
        t.join();

    vector<int> toReturn;
    for (vector<vector<int>>::iterator it = results.begin(); it != results.end(); ++it)
        for (int i = 0; i < (*it).size(); i++)
            toReturn.push_back((*it)[i]);

    return toReturn;

}

int main() {

    vector<int> leaderboard = {100, 90, 90, 80, 75, 60};
    vector<int> playerScores = {50, 70, 10, 60, 5, 90, 80, 20, 75, 85, 35, 78};

    vector<int> results = climbingLeaderboard(leaderboard, playerScores);
    for (vector<int>::iterator it = results.begin(); it != results.end(); ++it)
        cout << *it << "\n";

}