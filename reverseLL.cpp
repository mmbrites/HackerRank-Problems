#include <iostream>
#include <vector>

using std::cout;
using std::vector;

SinglyLinkedListNode {

    int data;
    SinglyLinkedListNode* next;

};

// Best Solution
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {

    auto cur = llist;  // best to remember
    SinglyLinkedListNode* prev = NULL;
    while(cur){
        auto next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;        
    }
    return prev;

}

// Okay Solution :)
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {

    vector<SinglyLinkedListNode *> elements;

    while (llist != nullptr) {
        elements.push_back(llist);
        llist = llist->next;
    }
    
    for (int i = 0; i < elements.size(); i++) {
        
        if (i == 0)
            elements[i]->next = nullptr;
        else
            elements[i]->next = elements[i - 1];
        
    }
        
    return elements[elements.size() - 1];   

}

int main() {


}