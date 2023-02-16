


    Node * move_last_to_first( Node *head) 
    {
        if(head==NULL) return head;
        Node* prev=NULL;
        Node* curr=head;
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        curr->next=head; // head is the first Node of linked list it
        return curr;
    }
