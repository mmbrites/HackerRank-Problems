#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int hackerlandRadioTransmitters(std::vector<int> & housePositions, int transmitterRadius) 
{

    int radios = 1;

    std::sort(housePositions.begin(), housePositions.end());

    int startPosition = housePositions[0];
    int radioPosition = housePositions[0];

    for (int index = 0; index < housePositions.size() - 1; index++)
    {

        if (housePositions[index + 1] - startPosition <= transmitterRadius)
        {
            radioPosition = housePositions[index + 1];
        }

        if (housePositions[index + 1] - radioPosition > transmitterRadius)
        {
            radios++;
            startPosition = housePositions[index + 1];
            radioPosition = housePositions[index + 1];
        }

    }

    return radios;

}

int main()
{

    const char * filename = "hackerland-testcase1.txt";
    std::fstream testCaseFileStream;
    testCaseFileStream.open(filename);

    int arraySize, transmitterRadius;

    testCaseFileStream >> arraySize;
    testCaseFileStream >> transmitterRadius;

    std::vector<int> housePositions;
    housePositions.reserve(arraySize);

    int iteration = 1;
    while (iteration <= arraySize)
    {
        int house;
        testCaseFileStream >> house;
        housePositions.push_back(house);
        iteration++;
    }
    
    std::cout << hackerlandRadioTransmitters(housePositions, transmitterRadius) << std::endl;

}