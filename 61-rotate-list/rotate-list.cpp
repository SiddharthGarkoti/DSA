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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        int size=1;
        while(temp->next){
            size++;
            temp=temp->next;
        }
        k%=size;
        if(k==0) return head;
        temp->next=head; //cycle created
        temp=head;
        int rotate=size-k;
        for(int i=1;i<rotate;i++) temp=temp->next;
        ListNode* Newhead=temp->next; //new strt found
        temp->next=NULL;//break the cycle
        return Newhead;
    }
};