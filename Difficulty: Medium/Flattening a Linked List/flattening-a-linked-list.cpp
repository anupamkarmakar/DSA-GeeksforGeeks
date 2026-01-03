/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        Node *newLL = new Node(0);
        vector<int> vec;
        Node *p=root;
        
        while(p){
            Node *q=p;
            while(q){
                vec.push_back(q->data);
                q=q->bottom;
            }
            p=p->next;
        }
        
        sort(vec.begin(),vec.end());
        Node *t=newLL;
        for(int i=0;i<vec.size();i++){
            Node *temp=new Node(vec[i]);
            t->bottom=temp;
            t=temp;
        }
        
        return newLL->bottom;
    }
};