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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        int x=b-a+1;
        while(a>1 && temp){
            a--;
            temp=temp->next;
        }
        ListNode* temp2=temp;
        while(x>=0 && temp2){
            temp2=temp2->next;
            x--;
            }
        temp->next=list2;
        while(temp->next) temp=temp->next;
        temp->next=temp2;
        return list1;
    }
};