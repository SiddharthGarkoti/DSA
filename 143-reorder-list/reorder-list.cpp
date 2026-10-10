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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            dummy=dummy->next;
        }
        dummy->next=NULL;//List breaking
        ListNode* prev=NULL;
        while(slow){
            ListNode* nxt=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nxt;
        }
        dummy=head;//strt point //prev second strt point
        ListNode* temp=dummy;// intrator
        dummy=dummy->next;
        bool check=true;
        while(dummy && prev){
            if(check){
                temp->next=prev;
                temp=temp->next;
                prev=prev->next;
                check=false;
            }
            else{
                temp->next=dummy;
                temp=temp->next;
                dummy=dummy->next;
                check=true;
            }  
        }
        if(dummy) temp->next=dummy;
        else if(prev) temp->next=prev; 
    }
};