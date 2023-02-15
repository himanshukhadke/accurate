// link - https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
// read about the proof


    void removeLoop(Node* head)
    {
        Node *slow=head;
        Node *fast=head;
        int flag=0;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                break;
            }
        }
        if(slow==fast){
            slow=head; // initialize the slow to head
            if(slow==fast){
                //This condition when both meet at head pointer.
                while(fast->next!=slow){
                    fast=fast->next;
                }
            }else{
                while(slow->next!=fast->next){
                    slow=slow->next;
                    fast=fast->next;
                }
            }
            fast->next=NULL;
        }
    }
