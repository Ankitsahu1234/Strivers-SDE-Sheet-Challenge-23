vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here

    vector<int> res;
    if(root==NULL)
        return res;
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0; i<sz; i++)
        {
            TreeNode<int> *curr=q.front();
            q.pop();
            if(i==0)
                res.push_back(curr->data);
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    return res;
}
