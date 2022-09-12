Node* reverseDLL(Node * head)
{
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