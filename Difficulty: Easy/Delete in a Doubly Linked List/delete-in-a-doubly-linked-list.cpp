/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        struct Node *p,*q;
        p=head,q=NULL;
        
        if(x==1){
            head=head->next;
            head->prev=NULL;
            delete p;
        }
        
        else{
            for(int i=0;i<x-1;i++){
                q=p;
                p=p->next;
            }
            if(p){
                q->next=p->next;
                if(p->next)
                    p->next->prev=q;
                delete p;
            }
        }
        return head;
    }
};