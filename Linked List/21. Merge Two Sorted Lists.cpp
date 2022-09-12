// iterative code:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;
        
        while( list1 && list2){
            if(list1 -> val >= list2 -> val){
                dummy -> next = list2;
                list2 = list2 -> next;
                dummy = dummy -> next;
            }
                
            else{
                dummy -> next = list1;
                list1 = list1 -> next;
                dummy = dummy -> next;
            }    
        }

        while( list1){
            dummy -> next = list1;
            list1 = list1 -> next;
            dummy = dummy -> next;
        }
        
        while( list2){
            dummy -> next = list2;
            list2 = list2 -> next;
            dummy = dummy -> next;
        }
        
        return temp -> next;
        
    }
};

// recursive code
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