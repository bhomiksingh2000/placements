class Solution {
public:
    void reorderList(ListNode* head) {
        int count=0;
        ListNode* temp = head;
        
        while(temp){
            count++;
            temp = temp -> next;
        }
    
        ListNode* end = head;
        ListNode* start = head; 
        int e = count - k;
        
        while( k-1){
            k--;
            start = start -> next;  
        }
        
     
        while(e){
            e--;
            end=end->next; 
        }
        
        int x=start->val;
        start->val=end->val;
        end->val=x;
        
        return head;
    }
};