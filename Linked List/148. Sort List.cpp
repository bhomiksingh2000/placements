class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if( !list1 )
            return list2;
        
        if(!list2)
            return list1;
        
        ListNode* curr;
        
        if(list1 -> val < list2 -> val){
            curr = list1;
            curr -> next = mergeTwoLists( list1 -> next, list2);
        }
        
        else{
            curr = list2;
            curr -> next = mergeTwoLists( list1, list2 -> next);
        }
            
        
        return curr;
    }
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow ->next;
        }
        
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head -> next)  // either the list has 1 node or 0 nodes.
            return head;
            
        ListNode* mid = findMid(head);
        ListNode* right = mid -> next;
        
        // now dividing into 2 lists, 
        mid -> next = NULL;
        
        ListNode* left = sortList(head);
                 right = sortList(right);
        
        // merge those two lists:
        return mergeTwoLists(left,right);
        
    }
};