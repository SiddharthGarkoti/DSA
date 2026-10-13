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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy=head;
        ListNode* temp=head->next;
        int n=2;
        while(temp){
            int i=1;
            ListNode* move=temp;
            while(move && i<n){
                move=move->next;
                if(move) i++;
            }
            if(i%2!=0){
                if(!move) return head;
                dummy=move;
                temp=move->next;
            }
            else{
                ListNode* x=NULL;
                ListNode* l=temp;
                 while(i!=0 && temp){
                    ListNode* nxt=temp->next;
                    temp->next=x;
                    x=temp;
                    temp=nxt;
                    i--;
                 }
                dummy->next=x;
                l->next=temp;
                dummy=l;
            }
            n++;
        }
        return head;
    }
};