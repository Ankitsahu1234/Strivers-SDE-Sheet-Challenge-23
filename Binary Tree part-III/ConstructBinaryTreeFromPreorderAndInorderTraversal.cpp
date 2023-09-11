class Solution {
    TreeNode* buildHelper(vector<int> &preorder, vector<int> &inorder, int &rootIdx, int left, int right)
    {
        if(left>right)
            return NULL;
        int pivot=left;
        while(inorder[pivot]!=preorder[rootIdx])
            pivot++;
        rootIdx++;
        TreeNode *newNode=new TreeNode(inorder[pivot]);
        newNode->left=buildHelper(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right=buildHelper(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int rootIdx=0;
        return buildHelper(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
};
