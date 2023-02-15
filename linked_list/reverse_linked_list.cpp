// link - https://leetcode.com/problems/reverse-linked-list/description/


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


// Iterative Approach 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=NULL;
        while(curr){
            nxt = curr->next;    // storing next pointer so to not lose linked list
            curr->next = prev;   // reversing the next link to prev link
            prev = curr;         // store curr pointer as prev so we can proceed with reversing 
            curr = nxt;          // process next node similarly
        }
        return prev;
    }
};

// Recursive Approach 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *tmp=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return tmp;
    }
};
