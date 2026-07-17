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
    int maxdepth(TreeNode* root) {
        if(root == nullptr) return 0  ;
        int lh = maxdepth(root->left)  ;
        int rh = maxdepth(root->right) ; 

        return 1+max(lh , rh) ; 
    }
    TreeNode* helper(TreeNode* root , int curr , int maxd) {
        if(root == nullptr) {
            return nullptr ; 
        }
        if(curr == maxd) return root ; 

        TreeNode* lh = helper(root->left , curr+1 ,maxd) ; 
        TreeNode* rh =  helper(root->right , curr+1 , maxd) ; 

        if(lh != nullptr && rh!= nullptr) {
            return root ; 
        }

        return lh != nullptr ? lh : rh ; 
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxd = maxdepth(root) ; 
        return helper(root , 1 , maxd )  ;
    }
};