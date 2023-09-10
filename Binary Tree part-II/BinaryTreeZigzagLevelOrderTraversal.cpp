class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // BFS (Level Order Traversal)
      
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;

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
            if(flag==true)
            {
                reverse(temp.begin(), temp.end());
            }
            flag=!flag;
            res.push_back(temp);
        }
        return res;
    }
};
