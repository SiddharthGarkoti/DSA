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
    int pairSum(ListNode* head) {
        int x=0;
        ListNode* temp=head;
        if(!head->next->next) return (head->val+head->next->val);
        while(temp){
            x++;
            temp=temp->next;
            }
        int half=x/2;
        ListNode* move=new ListNode(0);
        move->next=head;
        for(int i=0;i<half;i++){
            move=move->next; //one step before the half point
        }
        ListNode* curr=move->next;
        ListNode* prev=NULL;
        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        move->next=prev;
        curr=move->next;//one pint beyond half
        int mx=-1;
        while(curr){
            mx=max(mx,curr->val+head->val);
            head=head->next;
            curr=curr->next;
        }
        return mx;
    }
};