class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        // Method 2: Iterative
        
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> st;
        map<TreeNode*, bool> mp;
        TreeNode *curr=root;
        st.push(root);
        while(!st.empty())
        {
            if(mp[curr]==false)
            {
                res.push_back(curr->val);
                mp[curr]=true;
            }
            if(curr->left!=NULL)
            {
                st.push(curr->left);
                curr=curr->left;
            }
            else
            {
                TreeNode *pNode=st.top();
                st.pop();
                if(pNode->right!=NULL)
                    st.push(pNode->right);
                if(pNode->right!=NULL)
                    curr=pNode->right;
            }
        }
        return res;
    }
};


// class Solution {
// public:

//     void preorder(TreeNode *root, vector<int> &res)
//     {
//         if(root==NULL)
//             return;
//         res.push_back(root->val);
//         preorder(root->left, res);
//         preorder(root->right, res);
//     }

//     vector<int> preorderTraversal(TreeNode* root) {
        
//         vector<int> res;
//         preorder(root, res);
//         return res;
//     }
// };
