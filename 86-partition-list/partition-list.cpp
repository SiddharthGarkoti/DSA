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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* newHead=new ListNode(0);
        ListNode* moreEnd=new ListNode(0);
        ListNode* less =newHead;
        ListNode* more =moreEnd;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                less->next=temp;
                less=less->next;
            }
            else{
                more->next=temp;
                more=more->next;
            }
            temp=temp->next;
        }
        more->next=NULL;
        less->next=moreEnd->next;
        return newHead->next;
    }
};