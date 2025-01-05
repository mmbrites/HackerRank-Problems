#include <iostream>
#include <vector>
#include <queue>

int cookies(int sweetness, std::priority_queue<int, std::vector<int>, std::greater<int>> cookiesSweetness)
{

    int iterations = 0;

    while (cookiesSweetness.top() < sweetness)
    {

        if (cookiesSweetness.size() == 1)
            return -1;

        int leastSweetCookie = cookiesSweetness.top();
        cookiesSweetness.pop();
        int secondLeastSweetCookie = cookiesSweetness.top();
        cookiesSweetness.pop();
        int newCookieSweetness = leastSweetCookie + 2 * secondLeastSweetCookie;

        cookiesSweetness.push(newCookieSweetness);
        
        iterations++;
    
    }

    return iterations;

}

int main()
{

    int numberOfCookies, sweetness;
    std::cin >> numberOfCookies;
    std::cin >> sweetness;

    std::priority_queue<int, std::vector<int>, std::greater<int>> cookiesSweetness;

    int currentCookie = 1;
    while (currentCookie <= numberOfCookies)
    {

        int currentCookieSweetness;
        std::cin >> currentCookieSweetness;

        cookiesSweetness.push(currentCookieSweetness);
        currentCookie++;

    }

    std::cout << cookies(sweetness, cookiesSweetness) << std::endl;

}