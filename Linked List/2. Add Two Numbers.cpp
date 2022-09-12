class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int ans = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while(l1 && l2){
            int sum = l1 -> val + l2 -> val + carry ;
            temp -> next = new ListNode (sum%10);
            carry = sum/10;
            l1 = l1 -> next;
            l2 = l2 -> next;
            temp = temp -> next;
            
        }
        
        while(l1){
            int sum = l1 -> val + carry;
            temp -> next = new ListNode (sum%10);
            carry = sum/10;
            l1 = l1 -> next;
            temp = temp -> next;
        }
        
        while(l2){
            int sum = l2 -> val + carry;
            temp -> next = new ListNode (sum%10);
            carry = sum/10;
            l2 = l2 -> next;
            temp = temp -> next;
        }
        
        if(carry){
            temp -> next = new ListNode (carry);
            
        }
        return dummy -> next;
        
    }
};