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
    vector<int> leafs(TreeNode* root) {
        vector<int> ans ; 
        if(root == nullptr) return ans ; 
         
        stack<TreeNode*> st ; 
        st.push(root) ; 

        while(!st.empty()) {
            TreeNode* node = st.top() ; 
            st.pop() ; 

            if(!node->left && !node->right) {
                ans.push_back(node->val)  ; 
            }
            if(node->right) {
                st.push(node->right) ; 
            }if(node->left) {
                st.push(node->left) ; 
            }
        }
        return ans  ; 

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1 = leafs(root1) ; 
        vector<int> ans2 = leafs(root2) ; 

        if(ans1 == ans2) {
            return true ; 
        }

        return false ; 
    }
};