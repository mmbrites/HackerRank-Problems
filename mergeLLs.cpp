// Not the best solution since it creates a list!
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    if (head1 == nullptr && head2 == nullptr)
        return nullptr;
    else if (head1 == nullptr)
        return head2;
    else if (head2 == nullptr)
        return head1;

    SinglyLinkedListNode * mergeList;
    SinglyLinkedListNode * head;
    
    if (head1->data > head2->data) {
   
        mergeList = new SinglyLinkedListNode(head2->data);
        head2 = head2->next;
    
    }
    else {
        
        mergeList = new SinglyLinkedListNode(head1->data);
        head1 = head1->next;
        
    }
    
    head = mergeList;
    
    while (head1 != nullptr && head2 != nullptr) {
        
        if (head1->data > head2->data) {
            
            SinglyLinkedListNode * node = new SinglyLinkedListNode(head2->data);
            node->next = nullptr;
            mergeList->next = node;
            head2 = head2->next;
            
        }
        else {
            
            SinglyLinkedListNode * node = new SinglyLinkedListNode(head1->data);
            node->next = nullptr;
            mergeList->next = node;
            head1 = head1->next;
            
        }
        
        mergeList = mergeList->next;
        
    }
    
    if (head1 != nullptr) {
    
        while (head1 != nullptr) {
            
            SinglyLinkedListNode * node = new SinglyLinkedListNode(head1->data);
            node->next = nullptr;
            mergeList->next = node;
            head1 = head1->next;
            mergeList = mergeList->next;
            
        }
        
    }
    if (head2 != nullptr) {
        
        while (head2 != nullptr) {
            
            SinglyLinkedListNode * node = new SinglyLinkedListNode(head2->data);
            node->next = nullptr;
            mergeList->next = node;
            head2 = head2->next;
            mergeList = mergeList->next;
            
        }
        
    }
    
    return head;

}

// Very good solution!
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head2){return head1;}
    if (!head1){return head2;}
    
    SinglyLinkedListNode* tmp;  // Zip through lists from here
   
    if (head1->data <= head2->data)
    {
        tmp = head1;
        tmp->next = mergeLists(head2, tmp->next);            
    }
    else
    {
        tmp = head2;
        tmp->next = mergeLists(head1, tmp->next);
    }

    return tmp;
} 

int main() {


    
}