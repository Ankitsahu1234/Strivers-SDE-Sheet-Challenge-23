class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        // Method 4: Iterative
        // Using one stack and will not changed the node. Best

        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> st;
        TreeNode *curr=root;

        while(!st.empty() || curr!=NULL)
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode *pNode=st.top();
                res.push_back(pNode->val);
                st.pop();
                curr=pNode->right;
            }
        }
        return res;
    }
};



// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
        
//         // Method 3: Iterative
//         // Using one stack and one unordered_map, this will not changed the node. Better

//         vector<int> res;
//         if(root==NULL)
//             return res;
//         stack<TreeNode*> st;

//         // left child has been visited: true
//         unordered_map<TreeNode*, bool> mp;

//         st.push(root);
//         while(!st.empty())
//         {
//             TreeNode *curr=st.top();
//             if(curr->left!=NULL && mp[curr->left]==false)
//             {
//                 st.push(curr->left);
//                 mp[curr->left]=true;
//             }
//             else
//             {
//                 res.push_back(curr->val);
//                 st.pop();
//                 if(curr->right!=NULL)
//                     st.push(curr->right);
//             }
//         }
//         return res;
//     }
// };



// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
        
//         // Method 2: Iterative
//         // Using one stack and the binary tree node will be changed. Easy ,not Practical

//         vector<int> res;
//         if(root==NULL)
//             return res;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty())
//         {
//             TreeNode *curr=st.top();
//             if(curr->left!=NULL)
//             {
//                 st.push(curr->left);
//                 curr->left=NULL;
//             }
//             else
//             {
//                 res.push_back(curr->val);
//                 st.pop();
//                 if(curr->right!=NULL)
//                     st.push(curr->right);
//             }
//         }
//         return res;
//     }
// };



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
