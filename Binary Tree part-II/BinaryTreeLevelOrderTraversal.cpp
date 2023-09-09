class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz=q.size();
            vector<int> temp;
            for(int i=0; i<sz; i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
