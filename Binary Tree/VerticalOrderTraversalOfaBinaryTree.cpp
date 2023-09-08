class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // Method 2: BFS

        vector<vector<int>> res;
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});

        while(!q.empty())
        {
            TreeNode *curr=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            mp[x][y].push_back(curr->val);
            if(curr->left!=NULL)
                q.push({curr->left, {x-1, y+1}});
            if(curr->right!=NULL)
                q.push({curr->right, {x+1, y+1}});
        }

        for(auto it: mp)
        {
            vector<int> col;
            for(auto p: it.second)
            {
                sort(p.second.begin(), p.second.end());
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};


// class Solution {
// private:
//     void traverse(TreeNode *root, int x, int y, map<int, map<int,vector<int>>> &mp)
//     {
//         if(root==NULL)
//             return;
//         mp[x][y].push_back(root->val);
//         traverse(root->left, x-1, y+1, mp);
//         traverse(root->right, x+1, y+1, mp);
//     }

// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
        
//         // Method 3: DFS
//         // Build the mapping recursively

//         vector<vector<int>> res;
//         map<int, map<int, vector<int>>> mp;
//         traverse(root, 0, 0, mp);

//         for(auto it: mp)
//         {
//             vector<int> col;
//             for(auto p: it.second)
//             {
//                 sort(p.second.begin(), p.second.end());
//                 col.insert(col.end(), p.second.begin(), p.second.end());
//             }
//             res.push_back(col);
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
        
//         vector<vector<int>> res;
//         queue<pair<TreeNode*, int>> q;
//         map<int, map<int, vector<int>>> mp;
//         q.push({root, 0});

//         int l=0;
//         while(!q.empty())
//         {
//             int sz=q.size();
//             for(int i=0; i<sz; i++)
//             {
//                 TreeNode *curr=q.front().first;
//                 int level=q.front().second;
//                 q.pop();
//                 mp[level][l].push_back(curr->val);
//                 if(curr->left!=NULL)
//                     q.push({curr->left, level-1});
//                 if(curr->right!=NULL)
//                     q.push({curr->right, level+1});
//             }
//             l++;
//         }
//         for(auto it: mp)
//         {
//             map<int, vector<int>> m=it.second;
//             vector<int> t;
//             for(auto it: m)
//             {
//                 vector<int> temp=it.second;
//                 sort(temp.begin(), temp.end());
//                 for(int x: temp)
//                     t.push_back(x);
//             }
//             res.push_back(t);
//         }
//         return res;
//     }
// };
