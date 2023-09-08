vector<string> res;

void solve(BinaryTreeNode<int> *root, string str)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        str+=to_string(root->data);
        res.push_back(str);
        return;
    }
    str+=to_string(root->data)+" ";
    solve(root->left, str);
    solve(root->right, str);
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    // Write your code here.

    solve(root, "");
    return res;
}
