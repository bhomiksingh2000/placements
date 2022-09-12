class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        // if intersection hoga to break ho jaega, and if intersection nhi h then they will both become NULL 
        
        
//         while(temp1!=temp2){
//             if(temp1)
//                 temp1 = temp1 -> next;
            
//             else
//                 temp1 = headB;
            
//             if(temp2)
//                 temp2 = temp2 -> next;
            
//             else
//                 temp2 = headA;
//         }
        
        while(temp1!=temp2){
            temp1=(temp1)?temp1 -> next:temp1 = headB;
            
            temp2=(temp2)?temp2 -> next:temp2 = headA;
        }
        
        return temp2;
        
    }
};