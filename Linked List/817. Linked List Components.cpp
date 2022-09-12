class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        int count=0;
        while(head!=NULL){
            if(mp[head->val]!=0){
                while(head!=NULL && mp[head->val]!=0){
                    head=head->next;
                }
                count++;
            }
            else{
                head=head->next;
            }
        }
        return count;
    }
};