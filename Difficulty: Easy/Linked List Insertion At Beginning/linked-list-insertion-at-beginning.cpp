/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        // Code here
        struct Node *t = new Node(x);
        
        if(head==NULL)
            return t;
    
        t->next=head;
        head=t;
        
        return head;
    }
};