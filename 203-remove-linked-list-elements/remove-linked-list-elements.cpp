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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* nt=head;
        if(head==NULL) return head;
        while(nt!=NULL && nt->val==val) nt=nt->next; //moving from initally val 
        ListNode* temp=nt;
        if(nt==NULL){
            head=NULL;
            return head;
        }
        head=nt;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->val==val){
                temp->next = temp->next->next;
                continue;
            }
            nt=temp->next;
            temp=temp->next;
        }
        return head;
    }
};