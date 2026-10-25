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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=head;
        int last=curr->val;
        ListNode* prev=curr;
        curr=curr->next;
        while(curr){
            if(prev->val>curr->val){
                ListNode* temp=curr; //finding
                prev->next=curr->next; // isloation part 1
                curr=curr->next; //isolation part 2
                ListNode* move=dummy->next; //inseration point
                ListNode* back=dummy; //prev;
                while(move && move!=curr && temp->val>move->val){
                    move=move->next;
                    back=back->next;
                }
                back->next=temp;
                temp->next=move;
            }
            else{
                curr=curr->next;
                prev=prev->next;
                }
        }
        return dummy->next;
    }
};