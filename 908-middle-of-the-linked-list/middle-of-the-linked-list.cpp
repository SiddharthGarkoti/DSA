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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        ListNode* mid=head;
        int midd=0;
        int size=0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
            if(size/2>midd){
                midd++;
                mid=mid->next;
            }
        }
        return mid;
    }
};