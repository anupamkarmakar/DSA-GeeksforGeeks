// User function Template for C++

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
vector<int> displayList(Node *head) {
    struct Node *p=head;
    vector<int>forward;
    while(p){
        forward.push_back(p->data);
        p=p->next;
    }
    return forward;
    
    vector<int>backward;
    p=p->prev;
    while(p){
        backward.push_back(p->data);
        p=p->prev;
    }
    return backward;
}