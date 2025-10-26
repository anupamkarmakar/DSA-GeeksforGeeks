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
    int lengthOfLoop(Node *head) {
        
        if(head==nullptr) return 0;  //If no head node exist
        
        Node *slow = head;
        Node *fast = head;
        
        // Detect cycle
        while(fast!= nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){ //Cycle found
                int count=1;
                slow=slow->next;
                
                while(slow!=fast){
                    slow=slow->next;
                    count++;
                }
                return count;
            }
        }
        return 0; //No cycle
    }
};