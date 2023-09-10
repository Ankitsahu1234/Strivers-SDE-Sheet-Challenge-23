class Solution {
    int height (TreeNode *root, bool &flag)
    {
        if(root==NULL)
            return 0;
        int left=height(root->left, flag);
        int right=height(root->right, flag);
        if(abs(left-right)>1)
        {
            flag=false;
        }
        return 1+max(left, right);
    }
    
public:
 
    bool isBalanced(TreeNode* root) {
        
        bool flag=true;
        height(root, flag);
        return flag;
    }
};
