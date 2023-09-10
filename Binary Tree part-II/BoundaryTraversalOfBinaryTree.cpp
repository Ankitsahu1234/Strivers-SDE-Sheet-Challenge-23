void traverseLeft(TreeNode<int> *root, vector<int> &res)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    res.push_back(root->data);
    if(root->left!=NULL)
        traverseLeft(root->left, res);
    if(root->left==NULL)
        traverseLeft(root->right, res);
}

void traverseRight(TreeNode<int> *root, vector<int> &res)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    if(root->right!=NULL)
        traverseRight(root->right, res);
    else
        traverseRight(root->left, res);
    res.push_back(root->data);
}

void traverseLeaf(TreeNode<int> *root, vector<int> &res)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        res.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, res);
    traverseLeaf(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.

    vector<int> res;
    if(root==NULL)
        return res;

    res.push_back(root->data);
    traverseLeft(root->left, res);
    traverseLeaf(root->left, res);
    traverseLeaf(root->right, res);
    traverseRight(root->right, res);

    return res;
}

