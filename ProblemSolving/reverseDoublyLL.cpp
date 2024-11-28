DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    
    DoublyLinkedListNode * head;
    
    while (llist != nullptr) {
        
        DoublyLinkedListNode * temporary = llist->prev;
        llist->prev = llist->next;
        llist->next = temporary;
        head = llist;
        llist = llist->prev;
        
    }
    
    return head;

}

int main() { 

    
}