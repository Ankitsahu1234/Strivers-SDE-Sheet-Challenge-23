class Solution {
public:

    void inorder(TreeNode *root, vector<int> &res)
    {
        if(root==NULL)
            return;
        res.push_back(root->val);
        inorder(root->left, res);
        inorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
