#include <bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.

    vector<int> res;
    queue<pair<TreeNode<int>*, int>> q;
    map<int, int> mp;
    q.push({root, 0});

    while(!q.empty())
    {
        TreeNode<int> *curr=q.front().first;
        int line=q.front().second;
        q.pop();
        if(mp.find(line)==mp.end())
            mp[line]=curr->data;
        if(curr->left!=NULL)
            q.push({curr->left, line-1});
        if(curr->right!=NULL)
            q.push({curr->right, line+1});
    }
    for(auto it: mp)
    {
        res.push_back(it.second);
    }
    return res;
}
