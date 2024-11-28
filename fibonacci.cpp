#include <iostream>

using std::cout;

int calculateValueAtIndex(int n, int previousPrevious, int previous) {

    if (n == 1)
        return previousPrevious;
    if (n == 2)
        return previous;

    return calculateValueAtIndex(n - 1, previous, previousPrevious + previous);

}

// This method counts 0 as the first number of the fibonacci sequence!
int fibonacci(int n) {
    
    if (n <= 0)
        return -1;

    return calculateValueAtIndex(n, 0, 1);
}

int main() {

    cout << fibonacci(10) << "\n";

}