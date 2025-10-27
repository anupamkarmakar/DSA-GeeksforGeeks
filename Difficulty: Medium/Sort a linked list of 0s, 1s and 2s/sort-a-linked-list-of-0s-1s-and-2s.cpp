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
        deque <int> arr;
        Node *p=head;
        
        while(p){
            arr.push_back(p->data);
            p=p->next;
        }
        
        sort(arr.begin(),arr.end());
        p=head;
        
        while(p){
            p->data=arr.front();
            arr.pop_front();
            p=p->next;
        }
        return head;
    }
};