#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

long powNoOverflow(long base, int exponent, long modulo)
{

    long number = base;
    for (int i = 1; i < exponent; i++)
        number = (number * base) % modulo;
    return number % modulo;

}

int legoBlocks(const int height, const int width)
{

    std::vector<long> combinationsPerRow;
    combinationsPerRow.reserve(width + 1);
    std::vector<long> totalCombinations;
    totalCombinations.reserve(width + 1);
    std::vector<long> solidCombinations;
    solidCombinations.reserve(width + 1);

    long modulo = pow(10, 9) + 7;

    for (int i = 0; i <= width && i < 3; i++)
        combinationsPerRow[i] = i;

    for(int i = 3; i <= width && i <= 4; i++)
        combinationsPerRow[i] = pow(2, i - 1); 

    for (int i = 5; i <= width; i++)
        combinationsPerRow[i] = (combinationsPerRow[i - 1] + combinationsPerRow[i - 2] + combinationsPerRow[i - 3] + combinationsPerRow[i - 4]) % modulo;

    for (int i = 0; i <= width; i++)
        totalCombinations[i] = powNoOverflow(combinationsPerRow[i], height, modulo);

    solidCombinations[0] = 0;
    solidCombinations[1] = 1;

    for (int i = 2; i <= width; i++) 
    {

        long unsolid = 0;
        for (int w = 1; w < i; w++)
            unsolid += (solidCombinations[w] * totalCombinations[i - w]) % modulo;


        solidCombinations[i] = (totalCombinations[i] - unsolid) % modulo;

    }

    long result = solidCombinations[width] % modulo;
    
    while (result < 0)
        result += modulo;

    return result;

}

int main()
{

    const char * filename = "legoBlocks-testcase1.txt";
    std::fstream testCaseFileStream;
    testCaseFileStream.open(filename);
    
    int iterations;
    testCaseFileStream >> iterations;

    for (int i = 1; i <= iterations; i++)
    {

        int height, width;

        testCaseFileStream >> height;
        testCaseFileStream >> width;

        // std::cout << "Test Case " << i << ": h = " << height << " w = " << width << std::endl;

        std::cout << legoBlocks(height, width) << std::endl;

    }

    testCaseFileStream.close();

}