class myStack {
  private:
    int size;
    int Top;
    int *S;
    
  public:
    myStack(int n) {
        size = n;
        Top = -1;
        S= new int[size];
    }

    bool isEmpty() {
        // check if the stack is empty
        if(Top == -1) return true;
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(Top == size-1) return true;
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()){
            return;
        }
        Top++;
        S[Top]=x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()){
            return;
        }
        Top--;
    }

    int peek() {
        // Returns the top element of the stack
        if(Top==-1) return -1;
        else return S[Top];
    }
};