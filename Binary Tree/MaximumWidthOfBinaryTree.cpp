class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long maxWidth=1;

        while(!q.empty())
        {
            long long sz=q.size();
            long long start=q.front().second;
            long long end=q.back().second;
            maxWidth=max(maxWidth, end-start+1);

            for(int i=0; i<sz; i++)
            {
                TreeNode *curr=q.front().first;
                long long idx=q.front().second-start;
                q.pop();

                if(curr->left!=NULL)
                    q.push({curr->left, 2*idx+1});
                if(curr->right!=NULL)
                    q.push({curr->right, 2*idx+2});
            }
        }
        return maxWidth;
    }
};
