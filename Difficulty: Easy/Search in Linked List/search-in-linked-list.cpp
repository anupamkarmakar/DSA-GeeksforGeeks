/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        struct Node *p=head;
        while(p){
            if(p->data==key){
              return true;
            } 
            p=p->next;
        }
        return false;
    }
};
