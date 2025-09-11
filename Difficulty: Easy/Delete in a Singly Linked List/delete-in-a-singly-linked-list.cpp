/*
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        struct Node *p,*q;
        p=head;
        q=NULL;
        if(x==1){
            head=head->next;
            delete p;
        }
        else{
            for(int i=0;i<x-1;i++){
                q=p;
                p=p->next;
            }
            if(p){
                q->next=p->next;
                delete p;
            }
        }
        return head;
    }
};