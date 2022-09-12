class Solution {
public:
    int solve(TreeNode* root, int &ans){
        if(!root)
            return 0;
        
        int l=max(0,solve(root->left, ans));
        int r=max(0,solve(root->right, ans));
        
        int sum=root->val+l+r;
        
        ans=max(sum,ans);
        
        return root->val + max(l,r);
        
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};