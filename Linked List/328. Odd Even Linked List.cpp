class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        
        ListNode* odd = dummy1;
        ListNode* even = dummy2;
        
        int i=1;
        while(head){
            if(i%2 == 0){
                even -> next = head;
                even = even -> next;
            }
            
            else{
                odd -> next = head;
                odd = odd -> next;
            }
            
            i++;
            head = head -> next;
        }
        
        odd -> next = dummy2 -> next;
        even->next=NULL;
        return dummy1 -> next;
    }
};