class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr=head;
        vector<int> ans;
        int flag=0;
        while(curr!=NULL)
        {   flag=0;
            ListNode* temp=curr->next;
            while(temp!=NULL)
            {
                if(temp->val>curr->val)
                {
                    ans.push_back(temp->val);
                    flag=1;
                    break;
                }
                temp=temp->next;
            }
            if(flag==0) ans.push_back(0);
            curr=curr->next;
            
        }
        return ans;
    }
};