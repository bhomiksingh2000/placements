class Solution {
public:
    unordered_map<TreeNode*,int> mp;
    int solve(TreeNode* root){
        if(!root)
            return 0;
        
        if(mp[root]>0)
            return mp[root];
        
        // take:
        int l1=0,r1=0;
        if(root->left)
            l1=solve(root->left->left)+solve(root->left->right);
        
        if(root->right)
            r1=solve(root->right->left)+solve(root->right->right);
        
        // not take:
        int notTake=solve(root->left)+solve(root->right);
        
        return mp[root]=max(root->val+l1+r1,notTake);
        
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};