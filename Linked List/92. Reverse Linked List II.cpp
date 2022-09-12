// TC: O(N) , SC : O(1)
class Solution {
public:
    ListNode* rev( ListNode* head, ListNode* tail, int count , int right){
        
        ListNode* curr = head;
        ListNode* prev = tail;   // this step is very important.
        
        while(count <= right && curr){
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        
        return prev;
     }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode* curr = head;
        
        ListNode* tail = head;    // tail ko right ke 1 node  aage bhejna h
        int nodes = 0;
        
        while(tail){
            nodes++;
            tail = tail -> next;   
            if(nodes == right)   
                break;   
        }
        
        
        if(count == left){
            return rev ( curr, tail, count, right);
            
        }
        
        // now we will just move till curr is at 1 postion back of left 
        while(curr && curr -> next){
            count++;
            
            if(count == left){
                curr -> next = rev ( curr -> next, tail, count, right);
                break;
            }
                
            curr = curr -> next;  
        }
        return head;
    }
};



/* 
// METHOD_2 ONE PASS  
// TC : O(N), SC : O(N)


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* leftNode=head;
        for(int i = 1; i < left ; i++)
            leftNode=leftNode->next;
        
        ListNode* curr=leftNode;
        vector<int> nums;
        for(int i = 0; i < (right-left+1); i++){
            nums.push_back(curr->val);
            curr = curr->next;
        }
        
        reverse(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            leftNode->val=nums[i];
            leftNode=leftNode->next;
        }
        
        return head;
    }
};

*/

