/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        struct Node *curr=head;
        struct Node *t = new Node(x);
        if(head==NULL)
            return t;
            
        for(int i=0;i<p;i++){
            curr=curr->next;
        }
        if(curr){
            t->next=curr->next;
            t->prev=curr;
            
            if(curr->next){
                curr->next->prev=t;
            }
            curr->next=t;
        }
        return head;
    }
};