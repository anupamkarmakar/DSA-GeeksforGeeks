/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        struct Node *p=head,*q=head;
        while(p->next){
            p=p->next;
        }
        while(q!=p && q->prev!=p){
            swap(q->data,p->data);
            q=q->next;
            p=p->prev;
        }
        return head;
    }
};