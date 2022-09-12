/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if( !head || !head -> next )
            return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        int n=0;
        
        while(curr){
            ListNode* forward = curr -> next;
            
            if(forward){
                ListNode* nextNode = forward -> next; 
                curr -> next = nextNode;
                forward -> next = curr;
                if(prev)
                    prev -> next = forward;
                
                prev=curr;
                curr=nextNode;
                
                if(n==0)
                    head=forward;
                
                n++;
            }
            
            else
                break;
            
        }
        
        return head;
    }
};

// method-2 : recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
          if(head == NULL|| head->next == NULL) return head;
          ListNode* temp=head->next;
          head->next=swapPairs(temp->next);
          temp->next=head;
          return temp;
    }
};
