// method-1:
// using Linked List:
class MyCircularQueue {
public:
    class Node{
        public:
        int val;
        Node *next;

        Node(int x){
            val = x;
            next = NULL;
        }
    };

    Node * head = NULL;
    Node * tail = NULL;
    int size, capacity;
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(size < capacity){
            if(!head){
                Node * newNode = new Node(value);
                head = newNode;
                tail = head;
            }

            else{
                Node *newNode = new Node(value);
                tail -> next = newNode;
                tail = tail -> next;
            }

            size++;
            return true;
        }
        
        else
            return false;
    }
    
    bool deQueue() {
        if(head){
            // cout<< "front Node deleted 🫡"<<endl;
            Node * curr = head;
            head = head -> next;
            curr -> next = NULL;
            delete(curr);
            size--;
            return true;
        }
        
        return false;
    }
    
    int Front() {
         if(size > 0)
            return head -> val;
        
        return -1;
    }
    
    int Rear() {
        if(size > 0)
            return tail -> val;
        
        return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

//METHOD-2:

//using array:
class MyCircularQueue {
public:
    int *arr;
    int front; 
    int rear; 
    int size; 
    int capacity;
    
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        arr = new int[k];
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if(size < capacity){
            
            if(front == -1){
                arr[0]=value;
                front=0;
                rear=0;
            }
            
            else{
                rear = (rear + 1) % capacity; 
                arr[rear] = value;
            }
            
            size++;
            return true;
            
        }
        
        else
            return false;
    }
    
    bool deQueue() {
        if(size > 0){
            front = (front + 1) % capacity;
            size--;
            return true;
        }
        
        else
            return false;
    }
    
    int Front() {
        if(size > 0)
            return arr[front];
        
        else
            return -1;
        
    }
    
    int Rear() {
        if(size > 0)
            return arr[rear];
        
        else
            return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};


//METHOD-3:

// list stl
class MyCircularQueue {
public:
    int len;
    list<int>lst;
    MyCircularQueue(int k) {
        len=k;
    }
    
    bool enQueue(int value) {
           if(lst.size()==len) return false;
        lst.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(lst.empty()) return false;
        lst.pop_front();
        return true;
        
    }
    
    int Front() {
        if(lst.empty()) return -1;
        return lst.front();
    }
    
    int Rear() {
    if(lst.empty()) return -1;
        return lst.back();
        
    }
    
    bool isEmpty() {
        return lst.empty();
    }
    
    bool isFull() {
        return lst.size()==len;
    }
};