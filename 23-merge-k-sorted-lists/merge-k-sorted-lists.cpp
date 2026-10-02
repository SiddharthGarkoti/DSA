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
    ListNode* merge(ListNode* &A,ListNode* &B){
        if(!A) return B;
        else if(!B) return A;
        ListNode* n;
        if(A->val>B->val){
            n=B;
            B=B->next;
        }
        else{
            n=A;
            A=A->next;
        }
        ListNode* NewHead=n;
        while(A && B){
        if(A->val>B->val){
            n->next=B;
            B=B->next;
        }
        else{
            n->next=A;
            A=A->next;
        }
        n=n->next;
        }
        if(!A) n->next=B;
        else n->next=A;
        return NewHead;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        while(lists.size()>1){
            ListNode* A=lists[lists.size()-1];
            lists.pop_back();
            ListNode* B=lists[lists.size()-1];
            lists.pop_back();
            ListNode* C=merge(A,B);
            lists.push_back(C);
        }
        return lists[0];
    }
};