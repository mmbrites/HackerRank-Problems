#include <iostream>
#include <math.h>

using std::cout;

int pageCount(int n, int p) {
    
    if (p <= std::ceil(n / 2))
        return p / 2;
    else {
        if (n % 2 == 0)
            return (n - p + 1) / 2;
        else
            return (n - p) / 2;
    }

}

int main() {

    cout << pageCount(5, 4) << "\n";

}