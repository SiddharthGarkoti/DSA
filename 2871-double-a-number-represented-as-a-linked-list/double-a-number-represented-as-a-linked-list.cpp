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
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=new ListNode(0);
        ListNode* Newhead=temp;
        ListNode* moving=Newhead;
        int carry=0;
        if(!head->next){
            if(head->val>4){
                head->next=new ListNode((head->val*2)%10);
                head->val=1;
                return head;
            }
            head->val*=2;
            return head;
        }
        if(head->val>4){
            temp->val=1;
            temp->next=new ListNode(0);
            temp=temp->next;
            moving=moving->next;
        }
        temp->val=(head->val*2)%10;
        temp->next=new ListNode(0);
        temp=temp->next;
        head=head->next;

        while(head){
            int hold=(head->val*2);
            temp->val=hold%10;
            if(hold>9) carry=1;
            else carry=0;
            moving->val=moving->val+carry;
            head=head->next;
            if(!head) break;
            temp->next=new ListNode(0);
            temp=temp->next;
            moving=moving->next;
        }
        return Newhead;
    }
};