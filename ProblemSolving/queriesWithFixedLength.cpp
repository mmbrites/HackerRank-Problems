#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>

int windowMaxIndex(const std::vector<int> & sequence, int index, int window) 
{
    int maxIndex = index;
    for (int i = index + 1; i < index + window; ++i)
        if (sequence[i] > sequence[maxIndex])
            maxIndex = i;
    return maxIndex;
}


std::vector<int> solve(const std::vector<int> & sequence, const std::vector<int> & queries)
{
    std::vector<int> results;
    results.reserve(queries.size());

    for (int index = 0; index < queries.size(); index++)
    {
        int query = queries[index];
        int minimum = std::numeric_limits<int>::max();
        if (query == 1)
        {
            for (int i = 0; i < sequence.size(); i++)
            {
                if (sequence[i] < minimum)
                    minimum = sequence[i];
            }
        }
        else
        {
            int maxIndex = -1;
            for (int j = 0; j <= sequence.size() - query; j++)
            {
                if (maxIndex < j)
                    maxIndex = windowMaxIndex(sequence, j, query);
                else if (sequence[maxIndex] < sequence[j + query - 1])
                    maxIndex = j + query - 1;

                if (minimum > sequence[maxIndex])
                    minimum = sequence[maxIndex];
            }
        }
        results.push_back(minimum);
    }
    
    return results;
}

int main()
{
    const char * filename = "queriesWFL-testcase.txt";
    std::fstream testCaseFileStream;
    testCaseFileStream.open(filename);

    int sequenceSize, queriesSize;
    testCaseFileStream >> sequenceSize;
    testCaseFileStream >> queriesSize;

    std::vector<int> sequence;
    sequence.reserve(sequenceSize);
    for (int index = 1; index <= sequenceSize; index++)
    {
        int sequenceNumber;
        testCaseFileStream >> sequenceNumber;
        sequence.push_back(sequenceNumber);
    }

    std::vector<int> queries;
    queries.reserve(queriesSize);
    for (int index = 1; index <= queriesSize; index++)
    {
        int query;
        testCaseFileStream >> query;
        queries.push_back(query);
    }

    // DEBUG

    std::cout << "[DEBUG]" << std::endl;

    std::cout << "Sequence size: " << sequenceSize << std::endl;
    std::cout << "Queries size: " << queriesSize << std::endl;

    for (int index = 0; index < sequenceSize; index++)
        std::cout << "sequence[" << index << "]: " << sequence[index] << std::endl;

    for (int index = 0; index < queriesSize; index++)
        std::cout << "queries[" << index << "]: " << queries[index] << std::endl;

    // FINISHED DEBUG

    std::cout << "[RELEASE]" << std::endl;

    std::vector<int> results = solve(sequence, queries);
    for (int index = 0; index < results.size(); index++)
        std::cout << results[index] << std::endl;
}