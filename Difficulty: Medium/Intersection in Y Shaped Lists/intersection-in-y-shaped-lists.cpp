/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        Node *p=head1, *q=head2;
        while(p!=q){
            p= p->next!=nullptr ? p->next : head2;
            q= q->next!=nullptr ? q->next : head1;
        }
        return p;
    }
};