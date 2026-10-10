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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            dummy=dummy->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL){ //when odd no of elements
            slow=slow->next;
        }
        dummy->next=NULL;
        ListNode* prev=NULL;
        while(slow!=NULL){
            ListNode* nxt=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nxt;
        } 
        while(prev){
            if(head->val!=prev->val) return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};