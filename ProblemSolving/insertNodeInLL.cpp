SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {

    // Node Creation
    SinglyLinkedListNode * node = new SinglyLinkedListNode(data);
    
    // Check if the LL is empty
    if (llist == nullptr) {
        node->next = nullptr;
        return node;
    }
    
    // Insert at the beginning - in those cases we only need the previous 'head'
    if (position == 0) {
        
        node->next = llist;
        return node;
        
    }
    else { 
    
        SinglyLinkedListNode * head = llist;
        int currentIndex = 0;
        while (currentIndex < position - 1) {
            
            llist = llist->next;
            currentIndex++;
        
        }
        
        SinglyLinkedListNode * nextNode = llist->next;
        llist->next = node;
        node->next = nextNode;
        return head;
    
    }

}

int main() {



}