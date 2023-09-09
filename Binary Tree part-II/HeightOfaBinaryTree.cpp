class Solution {
private:
    int height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int left=height(root->left);
        int right=height(root->right);
        return 1+max(left, right);
    }

public:
    int maxDepth(TreeNode* root) {
        
        return height(root);
    }
};
