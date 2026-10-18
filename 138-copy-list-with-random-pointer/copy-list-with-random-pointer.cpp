/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* temp=head;
        while(temp){
            Node* A=new Node(temp->val);
            Node* B=temp->next;
            temp->next=A;
            A->next=B;
            temp=B;
        }
        temp=head;
        while(temp){
            Node* A=temp->next;
            if(temp->random) A->random=temp->random->next;
            temp=temp->next->next;
        }
        Node* res=head->next;
        temp=head;
        Node* nhead=res;
        while(temp){
            Node* A=temp->next;
            temp->next=A->next;
            if(A->next){
                A->next=A->next->next;
            }
            temp=temp->next;
        }
        return nhead;
    }
};