/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
  private:
    Node *top;

  public:
    myStack() {
        top = nullptr; 
    }

    bool isEmpty() {
        // check if the stack is empty
        return top==NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node *newNode = new Node(x);
        newNode->next = top;
        top=newNode;
    }

    void pop() {
        if(isEmpty()) return;
        Node *temp=top;
        top=top->next;
        delete temp;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty()) return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        Node *p=top;
        int count=0;
        while(p){
            count++;
            p=p->next;
        }
        return count;
    }
};