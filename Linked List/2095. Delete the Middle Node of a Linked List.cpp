class Solution {
public:
    ListNode* findMid ( ListNode* head ){
        ListNode* fast = head;
        ListNode* slow = head;
        
        while( fast && fast->next ){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* mid = findMid (head);
        ListNode* temp = head;
        
        if( mid == head)
            return head -> next;
        
        while( temp -> next != mid )
            temp = temp -> next;
            
        temp -> next = mid -> next;
        delete(mid);
        
        return head;
        
    }
};