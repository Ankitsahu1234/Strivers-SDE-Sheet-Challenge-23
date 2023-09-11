class Solution {
    int height(TreeNode *root, int &res)
    {
        if(root==NULL)
            return 0;

        int lSum=max(height(root->left, res), 0);
        int rSum=max(height(root->right, res), 0);

        int temp=root->val+lSum+rSum;
        res=max(res, temp);

        return root->val+max(lSum, rSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        int res=INT_MIN;
        height(root, res);
        return res;
    }
};
