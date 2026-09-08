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
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        temp=head;
        k%=size;
        if(k==0) return head;
        int rotate=size-k;
        for(int i=1;i<rotate;i++){
            temp=temp->next;
        }
        ListNode* Newhead =temp->next;
        ListNode* Nhead =Newhead;
        temp->next=NULL;
        while(Nhead->next) Nhead=Nhead->next;
        Nhead->next=head;
        return Newhead;

    }
};