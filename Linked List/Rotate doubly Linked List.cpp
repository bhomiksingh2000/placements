Node* reverseDLL(Node * head){
    //Your code here
        Node * curr = head;
        Node * prevNode = NULL;
        
        while(curr){
            Node * forward = curr -> next;
            curr -> next = prevNode;
            curr -> prev = forward;
            prevNode = curr;
            curr = forward;
        }
        return prevNode;
    }
    int len(Node *start){
        int count = 0;
        Node *curr = start;
        
        while(curr){
            count++;
            curr = curr -> next;
        }
        return count;
    }

    // main function:
    Node *rotateDLL(Node *start,int p)
    {
        //Add your code here
        int n  = len(start);
        p = p%n;
        
        Node *tail = start;
        int x = p;
        while(x-1){
            x--;
            tail = tail -> next;
        }
        
        Node *forward = tail -> next;
        tail -> next = NULL;
        tail = forward;
        
        // reverse till p-1:
        start = reverseDLL(start);
        
        // reverse from p:
        tail = reverseDLL(tail);
        
        Node *curr = start;
        
        while(curr -> next){
            curr = curr -> next;
        }
        
        curr -> next = tail;
        return reverseDLL(start);
        
    }