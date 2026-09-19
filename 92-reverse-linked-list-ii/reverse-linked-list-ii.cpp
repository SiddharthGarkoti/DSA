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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* before=dummy;
        for(int i=1;i<left;i++){
            dummy=dummy->next;
        }
        ListNode* strt=dummy->next;
        ListNode* end=head;
        for(int i=1;i<right;i++){
            end=end->next;
        }
        ListNode* temp=end->next;
        int x=right-left+1;
        while(x){
            ListNode* nxt=strt->next;
            strt->next=temp;
            temp=strt;
            strt=nxt;
            x--;
        }
        dummy->next=end;
        return before->next;
    }
};