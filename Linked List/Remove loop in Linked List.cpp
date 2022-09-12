class Solution
{
    public:
    /*
    When ever we want to find out the midpoint of linked list we will 
    start the fast from head -> next , i.e fast = head -> next
    otherwise when we want to  find out the loop then we will start 
    the fast from the head 
    */
    Node* detectLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast){
                return slow;
            }
        }
        
        return NULL;
    }
    void removeLoop(Node* head)
    {
        Node* slow = detectLoop(head);
        Node* curr = head;
        
        if(!slow){
            return ;
        }
        
        // move at same speed:
        while(slow!=curr){
            slow = slow -> next;
            curr = curr -> next;
        }
        
        // now we are at starting of loop
        Node * temp = slow -> next;
        while(temp -> next != slow)
            temp = temp -> next;
        
        temp -> next = NULL;
        
    }
};