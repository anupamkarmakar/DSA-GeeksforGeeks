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
  
    //   three dummy linked lists (0-list, 1-list, 2-list) and then merge them
  
    Node* segregate(Node* head) {
        // Dummy heads for three linked lists: 0s, 1s, 2s
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        
        // Current pointers
        Node *zero = zeroHead;
        Node *one = oneHead;
        Node *two = twoHead;
        
        // Temp ptr for travesal
        Node *temp = head;
        
        while(temp){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1){
                one->next=temp;
                one=one->next;
            }
            else if(temp->data==2){
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }
        
        zero->next=(oneHead->next ? oneHead->next : twoHead->next); //If there are no 1's
        one->next=twoHead->next; //If there are no 2's, it automatically points NULL
        two->next=nullptr; // end properly
        
        // newHead for ascessing all
        Node *newHead=zeroHead->next;
        
        // Clean up dummy Nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return newHead;
    }
};