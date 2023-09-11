class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        // Method 2: Iterative Solution

        int i=0, j=0;
        TreeNode *root=new TreeNode(0x80000000);
        TreeNode *pp=NULL, *ptr=root;

        stack<TreeNode*> st;
        st.push(root);

        while(j<in.size())
        {
            if(st.top()->val==in[j])
            {
                pp=st.top();
                st.pop();
                j++;
            }
            else if(pp!=NULL)
            {
                ptr=new TreeNode(pre[i]);
                pp->right=ptr;
                pp=NULL;
                st.push(ptr);
                i++;
            }
            else
            {
                ptr=new TreeNode(pre[i]);
                st.top()->left=ptr;
                st.push(ptr);
                i++;
            }
        }
        ptr=root->left;
        delete root;
        return ptr;
    }
};


// class Solution {
//     TreeNode* buildHelper(vector<int> &preorder, vector<int> &inorder, int &rootIdx, int left, int right)
//     {
//         if(left>right)
//             return NULL;
//         int pivot=left;
//         while(inorder[pivot]!=preorder[rootIdx])
//             pivot++;
//         rootIdx++;
//         TreeNode *newNode=new TreeNode(inorder[pivot]);
//         newNode->left=buildHelper(preorder, inorder, rootIdx, left, pivot-1);
//         newNode->right=buildHelper(preorder, inorder, rootIdx, pivot+1, right);
//         return newNode;
//     }

// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
//         int rootIdx=0;
//         return buildHelper(preorder, inorder, rootIdx, 0, inorder.size()-1);
//     }
// };
