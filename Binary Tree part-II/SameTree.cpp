class Solution {

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL) || (p!=NULL && q!=NULL && p->val!=q->val))
            return false;
        if(p==NULL && q==NULL)
            return true;
            
        bool a=isSameTree(p->left, q->left);
        bool b=isSameTree(p->right, q->right);
        if(a==true && b==true)
            return true;
        return false;
    }
};
