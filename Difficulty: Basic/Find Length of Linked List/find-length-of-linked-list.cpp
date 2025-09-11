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
    int getCount(Node* head) {
        struct Node *p=head;
        int count=0;
        while(p){
            count++;
            p=p->next;
        }
        return count;
    }
};