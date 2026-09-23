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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* newhead=dummy;
        dummy->next=head;
        ListNode* move=head;
        while(move){
            if(move->next!=NULL && move->val==move->next->val){
                while((move && move->next) && move->val==move->next->val) move=move->next;

                move=move->next;
                if(!move){
                    dummy->next=NULL;
                }
            }
            else{
                dummy->next=move;
                dummy=dummy->next;
                move=move->next;
            }
        }
        return newhead->next;
    }
};