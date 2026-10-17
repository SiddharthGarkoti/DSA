  /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* move=head;
        while(move){
            if(move->child){
                Node* nxt=move->next;
                Node* c=move->child;
                move->next=c;
                move->child=NULL;
                c->prev=move;
                flatten(c);
                while(c && c->next){
                    c=c->next;
                }
                c->next=nxt;
                if(nxt) nxt->prev=c;
            }
            move=move->next;
        }
        return head;
    }
};