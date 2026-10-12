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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int x=-1;
        int y=-1;
        int z=-1;
        bool first=false;
        vector<int> res(2);
        res[0]=INT_MAX;
        res[1]=INT_MIN;
        if(!head || !head->next) return {-1,-1};
        ListNode* temp=head->next;
        int left=head->val;
        int n=2;//temp postion
        while(temp && temp->next){
            int right=temp->next->val;
            int pos=temp->val;
            if((pos>right && pos>left) || (pos<left && pos<right)){
                if(!first){
                    z=n;
                    first=true;
                }
                if(x!=-1 && y!=-1) res[0]=min(y-x,res[0]);
                x=y;
                y=n;
                }
            left=temp->val;
            temp=temp->next;
            n++;
        }
        if(x==-1 || y==-1) return {-1,-1};
        res[0]=min(y-x,res[0]);
        res[1]=max(y-z,res[1]);
        return res;
    }
};