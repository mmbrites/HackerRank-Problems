#include <iostream>
#include <vector>
#include <climits>

const int ADD = 1;
const int DELETE = 2;
const int PRINT = 3;

// A heap cannot be represented using the usual binary tree approach because we need to scale up the tree. I will leave this struct intact, but remember that this is not use in the solution.
struct heapNode
{

    int value;
    heapNode * left;
    heapNode * right;

};

void addNode(std::vector<int> & heap, int elementValue)
{

    heap.push_back(elementValue);
    int index;
    if (heap.size() == 1)
        index = 0;
    else
        index = heap.size() - 1;

    while (elementValue < heap[(index - 1) / 2])
    {

        int temporaryStorage = heap[index];
        heap[index] = heap[(index - 1) / 2];;
        heap[(index - 1) / 2] = temporaryStorage;
        index = (index - 1) / 2;

    }

}

void printHeap(std::vector<int> & heap)
{
    for (int i = 0; i < heap.size(); i++)
        std::cout << i << ": " << heap[i] << std::endl;
}

void heapify(std::vector<int> & heap, int i)
{

    int leftIndex = i * 2 + 1;
    int rightIndex = i * 2 + 2;
    int smallest = i;

    if (leftIndex < heap.size() && heap[leftIndex] < heap[i])
        smallest = leftIndex;
    if (rightIndex < heap.size() && heap[rightIndex] < heap[smallest])
        smallest = rightIndex;

    if (smallest != i) 
    {
        int temporaryStorage = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temporaryStorage;
        heapify(heap, smallest);
    }

}

void deleteMinimumValue(std::vector<int> & heap)
{

    int currentValueIndex = 0;
    heap[currentValueIndex] = heap[heap.size() - 1];
    heap.pop_back();
    heapify(heap, 0);

}

void decreaseKey(std::vector<int> & heap, int elementValue)
{

    int index;
    for (int i = 0; i < heap.size(); i++)
    {
        if (heap[i] == elementValue)
        {
            index = i;
            break;
        }
    }

    heap[index] = INT_MIN;
    int parentValue = heap[(index - 1) / 2];

    while (parentValue > heap[index])
    {
        int temporaryStorage = heap[index];
        heap[index] = parentValue;
        heap[(index - 1) / 2] = temporaryStorage;
        index = (index - 1) / 2;
        parentValue = heap[(index - 1) / 2];
    }

}

void deleteNode(std::vector<int> & heap, int elementValue)
{

    decreaseKey(heap, elementValue);
    deleteMinimumValue(heap);

}

void print(std::vector<int> & heap)
{
    std::cout << heap[0] << std::endl;
}

int main()
{

    std::vector<int> heap;
    heap.reserve(10);

    int queries;
    std::cin >> queries;

    int currentQuery = 1;

    while (currentQuery <= queries)
    {

        int queryType, argument;
        std::cin >> queryType;

        switch (queryType)
        {

            case ADD:
                std::cin >> argument;
                addNode(heap, argument);
                break;

            case DELETE:
                std::cin >> argument;
                deleteNode(heap, argument);
                break;

            case PRINT:
                print(heap);
                break;

            default:
                std::cout << "Invalid query type!" << std::endl;
                return -1;

        }

        // printHeap(heap);
        currentQuery++;

    }

    // printHeap(heap);

}