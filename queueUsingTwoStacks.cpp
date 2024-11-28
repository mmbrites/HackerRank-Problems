#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

template<typename V>
class QueueUsingTwoStacks {

    public:
        QueueUsingTwoStacks() : stack1Active(true) { }
        
        void enqueue(V value) {

            if (stack1Active)
                stack1.push_back(value);
            else
                stack2.push_back(value);

        }

        void dequeue() {

            if (stack1Active) {

                for (int i = 1; i < stack1.size(); i++)
                    stack2.push_back(stack1[i]);

                stack1.clear();
                stack1Active = false;

            }
            else {

                for (int i = 1; i < stack2.size(); i++)
                    stack1.push_back(stack2[i]);

                stack2.clear();
                stack1Active = true;

            }

        }

        V first() {

            if (!stack1Active)
                return stack2[0];
            return stack1[0];

        }

    private:
        bool stack1Active;
        vector<V> stack1;
        vector<V> stack2;

};

void queryQueue(int queryType, int enqueueNumber, QueueUsingTwoStacks<int> & queue) {

    switch (queryType) {

        case 1: queue.enqueue(enqueueNumber); break;
        case 2: queue.dequeue(); break;
        case 3: cout << queue.first() << "\n"; break;
        default : cout << "lol\n";

    }

}

int main() {

    int currentQuery = 0;
    int queries;
    cin >> queries;
    cin.get(); // Ignore "new line"

    QueueUsingTwoStacks<int> q;

    while (currentQuery < queries) {

        int queryType;
        int enqueueNumber = 0;

        cin >> queryType;

        if (queryType == 1)
            cin >> enqueueNumber;

        queryQueue(queryType, enqueueNumber, q);

        currentQuery++;

    }

}