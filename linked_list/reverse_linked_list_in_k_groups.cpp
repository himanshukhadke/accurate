
// link - https://leetcode.com/problems/reverse-nodes-in-k-group/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// recursive Solution with Iterative reversal
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int count=0;
        ListNode *nxt=head;
        while(nxt){
            ++count;
            if(count==k)break;
            nxt=nxt->next;
        }
        if(count!=k) return head;
        ListNode *curr=head,*prev=NULL;
        while(count--){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};

// recursive way with recursive reversal 
class Solution {
public:

    ListNode* reverse(ListNode* head,int count){
        if(count==1) return head;
        ListNode *rev_head=reverse(head->next,count-1);
        head->next->next=head;
        head->next=NULL;
        return rev_head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int count=0;
        ListNode *nxt=head;
        while(nxt){
            ++count;
            nxt=nxt->next;
            if(count==k)break;
        }
        if(count!=k) return head;
        ListNode *prev=reverse(head,k);
        head->next = reverseKGroup(nxt,k);
        return prev;
    }
};


// Iterative way 
class Solution {
public:

    ListNode* reverse(ListNode* head,int count){
        if(count==1) return head;
        ListNode *rev_head=reverse(head->next,count-1);
        head->next->next=head;
        head->next=NULL;
        return rev_head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* start=NULL;
        ListNode* nxt=head;
        ListNode* prev_head = new ListNode();
        while(nxt){
            head=nxt;
            int count=0;
            while(nxt){
                ++count;
                nxt=nxt->next;
                if(count==k) break;
            }
            if(count==k){
                ListNode *rev_head=reverse(head,k);
                if(start==NULL) start=rev_head;
                prev_head->next=rev_head;
                prev_head=head;

            }else{
                prev_head->next=head;
                if(start==NULL){
                    start=head;
                }
                break;
            }
        }
        return start;
    }
};
