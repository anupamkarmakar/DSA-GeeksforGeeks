/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        if(!head || !head->next) return head;
        
        Node *temp=head->next;
        while(temp){
            
            if(temp->data==temp->prev->data){
                
                Node* nextNode=temp->next;
                
                temp->prev->next=temp->next;
                if(temp->next)
                    temp->next->prev=temp->prev;
                    
                delete temp;
                temp=nextNode;
            }
            
            else temp=temp->next;
        }
        
        return head;
    }
};