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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0); //fixed strt point
        ListNode* temp=head;
        int carry=0;
        while(l1 || l2){
            int h1=l1?l1->val:0;
            int h2=l2?l2->val:0;
            temp->val=h1+h2+carry!=10?(h1+h2+carry)%10:0;
            if(h1+h2+carry>9) carry=1;
            else carry=0;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
            if(!l1 && !l2) break;
            temp->next = new ListNode(0);
            temp=temp->next;
        }
        if(carry){
            temp->next=new ListNode(1);
        }
        return head;
    }
};