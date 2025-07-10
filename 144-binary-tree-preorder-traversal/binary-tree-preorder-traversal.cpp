/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // if(root == nullptr) return {};
        
        // vector<int> ans;
        // ans.push_back(root->val);

        // vector<int> left = preorderTraversal(root->left);
        // vector<int> right = preorderTraversal(root->right);

        // ans.insert(ans.end(), left.begin(), left.end());
        // ans.insert(ans.end(), right.begin(), right.end());

        // return ans;



        // without recursion we use stack and traverse
        vector<int>ans;
        if(root == NULL)return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right != NULL)st.push(root->right);
            
            if(root->left != NULL)st.push(root->left);
        }
        return ans;
    }
};
