class Solution {

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL) || (p!=NULL && q!=NULL && p->val!=q->val))
            return false;
        if(p==NULL && q==NULL)
            return true;
            
        bool left=isSameTree(p->left, q->left);
        bool right=isSameTree(p->right, q->right);
        if(left==true && right==true)
            return true;
        return false;
    }
};
