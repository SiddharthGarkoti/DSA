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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp=head;
        int size=1;
        while(temp->next){
            size++;
            temp=temp->next;
        }
        if(k==size){
            int t=temp->val;
            temp->val=head->val;
            head->val=t;
            return head;      
        }
        temp=head;
        ListNode *swap=head;
        for(int i=0;i<k-1;i++){
            temp=temp->next;
        }
        for(int i=0;i<size-k;i++){
            swap=swap->next;
        }
        int t=swap->val;
        swap->val=temp->val;
        temp->val=t;
        return head;
    }
};