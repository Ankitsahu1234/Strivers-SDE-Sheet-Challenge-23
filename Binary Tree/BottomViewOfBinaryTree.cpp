vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.

    vector<int> res;
    map<int, int> mp;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while(!q.empty())
    {
        TreeNode<int> *curr=q.front().first;
        int level=q.front().second;
        q.pop();
        if(mp.find(level)!=mp.end())
            mp[level]=curr->data;
        else
            mp[level]=curr->data;
        if(curr->left!=NULL)
            q.push({curr->left, level-1});
        if(curr->right!=NULL)
            q.push({curr->right, level+1});
    }
    for(auto it: mp)
    {
        res.push_back(it.second);
    }
    return res;
}

