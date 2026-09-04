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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        ListNode* mid=head;
        ListNode* mid2=mid;
        int size=0;
        int midd=0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
            if(size/2>midd){
                mid2=mid;
                mid=mid->next;
                midd++;
                }
        }
        if(size==1){
            head=NULL;
            return head;
        }
        mid2->next=mid2->next->next;
        return head;
    }
};