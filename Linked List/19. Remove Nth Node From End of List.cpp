/*
METHOD-1: 
By using fast & slow pointers 
*/

class Solution {
public:
    int len(ListNode* head){
        int length=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            length++;
        }
        
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        
        int length = len(head);
        if(length==n)
            return head->next;
        
        // k jumps 
        while(n--)
            fast=fast->next;
            
    
        // move at same speed
        while(fast && fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        
        ListNode* nextNode=slow->next;
        slow->next=slow->next->next;
        
        delete (nextNode);
        return head;
    }
};

/*
we can just find the length of the LL
and then nth node from the end will be (length - n) node
*/

