class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        map<int, map<int, vector<int>>> mp;
        q.push({root, 0});

        int l=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode *curr=q.front().first;
                int level=q.front().second;
                q.pop();
                mp[level][l].push_back(curr->val);
                if(curr->left!=NULL)
                    q.push({curr->left, level-1});
                if(curr->right!=NULL)
                    q.push({curr->right, level+1});
            }
            l++;
        }
        for(auto it: mp)
        {
            map<int, vector<int>> m=it.second;
            vector<int> t;
            for(auto it: m)
            {
                vector<int> temp=it.second;
                sort(temp.begin(), temp.end());
                for(int x: temp)
                    t.push_back(x);
            }
            res.push_back(t);
        }
        return res;
    }
};
