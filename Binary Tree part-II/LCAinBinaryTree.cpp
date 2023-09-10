class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL || root==p || root==q)
            return root;
        
        TreeNode *left=lowestCommonAncestor(root->left, p, q);
        TreeNode *right=lowestCommonAncestor(root->right, p, q);
        if(left==NULL && right==NULL)
            return NULL;
        if(left!=NULL && right!=NULL)
            return root;
        if(left!=NULL && right==NULL)
            return left;
        else
            return right;
    }
};
