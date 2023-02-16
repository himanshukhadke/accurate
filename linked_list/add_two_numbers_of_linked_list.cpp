// link - below is the solution where number are stored as it is in linked list.
/*
l1 = 4 5 3 2->NULL
l2 =     0 6->NULL
ans= 4-> 5-> 3-> 8-> NULL

*/
class Solution {
public:
    int reverse(ListNode *l1,ListNode *l2,int n,int m,int i){
        int carry=0,sum=0;
        if(l1->next==NULL and l2->next==NULL){
            sum=l1->val+l2->val;
        }else if(n-i<=m){ // we can start considering both list (l1,l2);
            carry=reverse(l1->next,l2->next,n,m,i+1);
            sum=(l1->val+l2->val+carry);
        }else{  // consider longest list only. (l1)
            carry=reverse(l1->next,l2,n,m,i+1);
            sum=l1->val+carry;
        }
        carry=sum/10;
        l1->val=sum%10;
        return carry;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n=0,m=0;
        ListNode* temp=l1;
        while(temp){++n;temp=temp->next;};
        temp=l2;
        while(temp){++m;temp=temp->next;};
        if(m>n) {
            swap(l1,l2);
            swap(n,m);
        }
        int carry = reverse(l1,l2,n,m,0);
        if(carry>0){
            ListNode *temp=new ListNode(1);
            temp->next=l1;
            l1=temp;
        }
        return l1;
    }
};



// leetcode version :
class Solution {
public:
    bool reverse(ListNode *l1,ListNode *l2,int carry){
        if(l1) return carry>0?true:false;
        int sum=0;
        if(l1 and l2){
            sum=l1->val+l2->val+carry;
        }else if(l1){
            sum=(l1->val+carry);
        }
        carry=sum/10;
        l1->val=sum%10;

        return reverse(l1?l1->next:NULL,l2?l2->next:NULL,carry);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n=0,m=0;
        ListNode* temp=l1;
        while(temp){++n;temp=temp->next;};
        temp=l2;
        while(temp){++m;temp=temp->next;};
        if(m>n) {
            swap(l1,l2);
            swap(n,m);
        }
        bool carry = reverse(l1,l2,0);
        if(carry){
            ListNode *ca=new ListNode(1);
            temp=l1;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ca;
        }
        return l1;
    }
};
