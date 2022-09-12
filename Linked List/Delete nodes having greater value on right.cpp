// first reverse , do easily by creating a maxx variable:
class Solution
{
    public:
    Node* reverse(Node* head)
   {
       if(head==NULL)
       {
           return NULL;
       }
       Node* prev=NULL;
       Node* curr=head;
       Node* nxt=curr->next;
       while(curr)
       {
           nxt=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nxt;
       }
       return prev;
   }
    Node *compute(Node *head)
    {   
        head=reverse(head);
        int  maxx=head->data;
        Node* curr=head->next;
        Node* prev=head;
        
        while(curr)
        {
            if(curr->data<maxx)
            {
                prev->next=curr->next;
                curr=curr->next;
                
            }
            else
            {   maxx=curr->data;
                prev=curr;
                curr=curr->next;
            }
        }
        head=reverse(head);
        return head;
    }
    
};