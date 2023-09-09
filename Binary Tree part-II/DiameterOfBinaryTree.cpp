class Solution {
    
    int height(TreeNode *root, int &res)
    {
        if(root==NULL)
            return 0;
        
        int left=height(root->left, res);
        int right=height(root->right, res);
        res=max(res, left+right);

        return 1+max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {

        int res=0;
        height(root, res);
        return res;
    }
};
