class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode * slow = head;
        ListNode * fast = head;
        bool isCycle = false;
        
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast){
                isCycle = true;
                break;
            }
        }
        
        
        if(!isCycle)
            return NULL;
            
        // now start slow from head, and fast at normal pace.
        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow;
 
    }
};