// link - https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1


    Node * removeDuplicates( Node *head) 
    {
         unordered_set<int> s;
         if(head==NULL){
             return head;
         }
         s.insert(head->data);
         Node *curr=head;
         while(curr->next!=NULL){
             if(s.find(curr->next->data)!=s.end()){
                 Node* nxt=curr->next;
                 delete(nxt);
                 curr->next=curr->next->next;
             }else{
                 s.insert(curr->next->data);
                 curr=curr->next;
             }
         }
         return head;
    }
