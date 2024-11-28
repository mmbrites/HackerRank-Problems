#include <iostream>
#include <string>
#include <math.h>

using std::cout;
using std::string;

int decimalToBinary(long n, char * number) {
    
    int position = 31;
    int bits = 0; // small optimization for when reversing the bits :)
    while (n != 0) {

        cout << position << "\n";
        number[position] = (n % 2) + 48;
        n /= 2;
        position--;
        bits++;
        
    }

    for(int i = position; i >= 0; i--)
        number[i] = '1';

    return bits; 
    
}

uint binaryToDecimal(char * toDecimal) {

    uint number = 0;
    for (int i = 0; i < 32; i++)
        if (toDecimal[i] == '1')
            number += std::pow(2, (32 - i - 1));

    return number;

}

/*
 * Complete the 'flippingBits' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long flippingBits(long n) {

    char number[33]; // Since the last character of a char array is always '\0', we need 33 positions for a 32-bit unsigned integer
    for (int i = 0; i < 33; i++)
        number[i] = 0;

    int bitsToFlip = decimalToBinary(n, number);

    cout << number << "\n";

    for (int i = 31; i > 31 - bitsToFlip; i--) {

        if (number[i] == '0')
            number[i] = '1';
        else
            number[i] = '0';

    }

    return binaryToDecimal(number);

}

// More efficient solution :) FUCKING HELL
long flippingBits(long n) {
    return ~((unsigned)n);
}

int main() {

    cout << flippingBits(2) << "\n";

}