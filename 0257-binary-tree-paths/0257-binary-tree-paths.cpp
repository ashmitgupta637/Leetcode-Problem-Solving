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
    void helper(TreeNode* root ,string path , vector<string>& result) {
        if(root == nullptr) return ; 
        if(path.empty()) {
            path += to_string(root->val) ; 

        }else{
            path += "->" + to_string(root->val) ; 
        }
        if(root->left == nullptr && root->right == nullptr) {
            result.push_back(path) ;
            return ; 
        }
        helper(root->left ,path,  result) ; 
        helper(root->right , path , result ) ; 

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result ;  
        
        helper(root ,"",  result) ;
        return result ;  
    }
};