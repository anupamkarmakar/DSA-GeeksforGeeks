class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
  private:
    Node *front;
    Node *rear;

  public:
    myQueue() {
        // Initialize your data members
        front=nullptr;
        rear=nullptr;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==nullptr;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node *newNode = new Node(x);
        if(!rear) rear=front=newNode;
        else{
            rear->next=newNode;
            rear=newNode;
        }
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()) return;
        Node *temp=front;
        front=front->next;
        if(front==nullptr) rear=nullptr;
        delete temp;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()) return -1;
        return front->data;
    }

    int size() {
        // Returns the current size of the queue.
        Node *counter=front;
        int count=0;
        while(counter){
            count++;
            counter=counter->next;
        }
        return count;
    }
};
