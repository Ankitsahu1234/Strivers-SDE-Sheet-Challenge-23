class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        // Method 2: Iterative
        // Using one stack and the binary tree node will be changed. Easy ,not Practical

        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *curr=st.top();
            if(curr->left!=NULL)
            {
                st.push(curr->left);
                curr->left=NULL;
            }
            else
            {
                res.push_back(curr->val);
                st.pop();
                if(curr->right!=NULL)
                    st.push(curr->right);
            }
        }
        return res;
    }
};

// class Solution {
// public:

//     void inorder(TreeNode *root, vector<int> &res)
//     {
//         if(root==NULL)
//             return;
//         inorder(root->left, res);
//         res.push_back(root->val);
//         inorder(root->right, res);
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
        
//         vector<int> res;
//         inorder(root, res);
//         return res;
//     }
// };
