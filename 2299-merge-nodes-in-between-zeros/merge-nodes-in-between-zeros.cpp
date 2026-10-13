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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev=head;
        ListNode* temp=head->next;
        while(temp && temp->next){
            int sum=0;
            while(temp->val!=0 && temp){
                sum+=temp->val;
                temp=temp->next;
            }
            prev->val=sum;
            if(temp->next)prev->next=temp;
            else{
                prev->next=NULL;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};