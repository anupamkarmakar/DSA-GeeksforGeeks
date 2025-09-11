/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        struct Node *t=new Node(x);
        
        if(head==NULL)
            return t;
            
        struct Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=t;
        return head;
    }
};