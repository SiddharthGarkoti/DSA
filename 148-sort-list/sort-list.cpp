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
    ListNode* merge(ListNode*a,ListNode*b){
        ListNode* newhead=new ListNode(0);
        ListNode* temp=newhead;
        while(a && b){
            if(a->val>b->val){
                temp->next=b;
                b=b->next;
            }
            else{
                temp->next=a;
                a=a->next;
            }
            temp=temp->next;
        }
        if(!a) temp->next=b;
        else if(!b) temp->next=a;
        return newhead->next;

    }
    ListNode* sortt(ListNode*head){
        if(!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;//break the list
        ListNode* left=sortt(head); // break left part further
        ListNode* right=sortt(slow);//break right part further
        return merge(left,right);

    }
public:
    ListNode* sortList(ListNode* head) {
       return sortt(head);
    }
};