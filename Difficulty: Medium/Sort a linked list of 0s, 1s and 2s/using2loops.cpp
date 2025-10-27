/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // Two pass solution...
        int count0=0, count1=0, count2=0;
        Node *p=head;
        
        while(p){
            if(p->data==0) count0++;
            else if(p->data==1) count1++;
            else count2++;
            p=p->next;
        }
        
        p=head;
        while(p){
            if(count0){
                p->data=0;
                count0--;
            }
            else if(count1){
                p->data=1;
                count1--;
            }
            else if(count2){
                p->data=2;
                count2--;
            }
            p=p->next;
        }
        return head;
    }
};