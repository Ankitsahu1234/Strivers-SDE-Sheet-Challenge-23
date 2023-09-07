class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        // Method 4: Iterative (Using 1 Stack and nullptr)

        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *curr=st.top();
            // All children node are visited
            if(curr==nullptr)
            {
                st.pop();
                res.push_back(st.top()->val);
                st.pop();
                continue;
            }
            // Use nullptr to mark parent node
            st.push(nullptr);
            // last in first out
            if(curr->right!=NULL)
                st.push(curr->right);
            if(curr->left!=NULL)
                st.push(curr->left);
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
        
//         // Method 3: Iterative (Using 1 Stack)
        
//         vector<int> res;
//         stack<TreeNode*> st;
//         TreeNode *last=NULL;
//         while(root!=NULL || !st.empty())
//         {
//             if(root!=NULL)
//             {
//                 st.push(root);
//                 root=root->left;
//             }
//             else
//             { 
//                 TreeNode *curr=st.top();
//                 if(curr->right!=NULL && last!=curr->right)
//                     root=curr->right;
//                 else
//                 {
//                     res.push_back(curr->val);
//                     last=curr;
//                     st.pop();
//                 }
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
        
//         // Method 2: Iterative (Using 2 Stack)
        
//         if(root==NULL)
//             return {};
//         vector<int> res;
//         stack<TreeNode*> st1, st2;
//         st1.push(root);
//         while(!st1.empty())
//         {
//             TreeNode *curr=st1.top();
//             st1.pop();
//             st2.push(curr);
//             if(curr->left!=NULL)
//                 st1.push(curr->left);
//             if(curr->right!=NULL)
//                 st1.push(curr->right);
//         }
//         while(!st2.empty())
//         {
//             res.push_back(st2.top()->val);
//             st2.pop();
//         }
//         return res;
        
//     }
// };

// class Solution {
// public:
    
//     void postorder(TreeNode *root, vector<int> &res)
//     {
//         if(root==NULL)
//             return;
//         postorder(root->left, res);
//         postorder(root->right, res);
//         res.push_back(root->val);
//     }
    
//     vector<int> postorderTraversal(TreeNode* root) {
        
//         vector<int> res;
//         postorder(root, res);
//         return res;
//     }
// };
