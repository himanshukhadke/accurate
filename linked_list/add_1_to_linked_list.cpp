// link - https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1


class Solution
{
    public:
    int reverse(Node *head){
        if(head->next==NULL){
            if(head->data+1<=9){
                head->data=head->data+1;
                return 0;
            }else{ 
                head->data=0;
                return 1;
            }
        }
        int carry=reverse(head->next);
        if((head->data+carry)<=9){
            head->data=head->data+carry;
            return 0;
        }
        head->data=0;
        return 1;
    }
    
    Node* addOne(Node *head) 
    {   
        int carry=reverse(head);
        if(carry>0){
            Node* temp=new Node(1);
            temp->next=head;
            return temp;
        }
        return head;
    }
};
