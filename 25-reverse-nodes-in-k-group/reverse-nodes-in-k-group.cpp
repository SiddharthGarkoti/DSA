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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        ListNode* nhead=dummy;
        dummy->next=head;//dummy created
        ListNode* temp=head;//itrator
        while(temp){
            ListNode* end=temp; //kth position finder
            for(int i=1;i<k;i++){
                end=end->next;
                if(!end) return nhead->next;
            }
            ListNode* strt=temp;
            ListNode* join=end->next;
            int x=k;
            ListNode* prev=NULL;
            while(x){
                ListNode* nxt=temp->next;
                temp->next=prev;
                prev=temp;
                temp=nxt;
                x--;
            }
            dummy->next=end;
            strt->next=temp;
            dummy=strt;
        }
        return nhead->next;
    }
};