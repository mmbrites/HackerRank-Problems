#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::vector;
using std::stack;

bool prime(int number) {

    int i = number;
    int times = 0;

    while (i > 1) {

        if (number % i == 0)
            times++;

        i--;

    }

    return times == 1;

}

vector<int> primeNumbers(int q) {

    vector<int> primes;
    int currentNumber = 2;

    while (primes.size() < q) {

        if (prime(currentNumber))
            primes.push_back(currentNumber);

        currentNumber++;

    }

    return primes;

}

vector<int> waiter(vector<int> number, int q) {
    
    vector<int> primes = primeNumbers(q);
    vector<int> answers;
    int iterations = 0;
    
    stack<int> stackA;

    for (int i = 0; i < number.size(); i++)
        stackA.push(number[i]);

    stack<int> stackB;
    
    while (iterations < q) {
        
        int size = stackA.size();
        vector<int> toA;
        for (int i = 0; i < size; i++) {

            int topStack = stackA.top();

            if (topStack % primes[iterations] == 0)
                stackB.push(topStack);
            else
                toA.push_back(topStack);

            stackA.pop();
        
        }

        while (stackB.size() != 0) {
            
            answers.push_back(stackB.top());
            stackB.pop();
        
        }

        for (int i = 0; i < toA.size(); i++)
            stackA.push(toA[i]);

        iterations++;
        
    }
    
    while (stackA.size() != 0) {
        
        answers.push_back(stackA.top());
        stackA.pop();
        
    }
    
    return answers;

}

int main() {

    vector<int> number = {3, 4, 7, 6, 5};
    vector<int> answers = waiter(number, 1);

    for (int answer : answers)
        cout << answer << " ";
    cout << "\n";

}