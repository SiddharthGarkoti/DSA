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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int n=0;
        while(temp){
            temp=temp->next;
            n++;
        }
        int wdow=n/k; //window size
        int extra=n%k; //extra
        vector<ListNode*> res;
        temp=head;
        while(temp){
            int xsize=wdow;
            if(extra!=0){
                extra--;
                xsize++;
            }
            ListNode* strt=temp;
            while(temp && xsize!=1){
                temp=temp->next;
                xsize--;
            }
            ListNode* end=temp->next;
            temp->next=NULL;
            res.push_back(strt);
            temp=end;
        }
        while(res.size()!=k) res.push_back(NULL);
        return res;
    }
};