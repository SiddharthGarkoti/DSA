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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp2=head->next;
        ListNode* ptr=head->next;
        while(temp!=NULL && temp->next!=NULL && temp2->next){
            temp->next=temp->next->next;
            temp2->next=temp2->next->next;
            temp=temp->next;
            temp2=temp2->next;
            }
            temp->next=ptr;
        
        return head;
    }
};