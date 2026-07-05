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
    TreeNode* build(vector<int>& postorder , int postStart , int postEnd , vector<int> & inorder , int inStart , int inEnd , unordered_map<int, int> & mp ) {
        if(inStart > inEnd || postStart >postEnd){
            return nullptr ; 
        }
        TreeNode* root = new TreeNode(postorder[postEnd]) ; 

        int inroot = mp[root->val] ; 
        int numsright =  inEnd - inroot ; 
        root->right = build(postorder  , postEnd-numsright , postEnd-1 , inorder , inroot+1 , inEnd , mp) ; 
        root->left = build(postorder  , postStart , postEnd-numsright-1 , inorder , inStart , inroot-1 , mp) ; 
        return root ; 

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int , int> mp ; 
        for(int i = 0 ; i < inorder.size() ; i++) {
            mp[inorder[i]] = i ; 
        }
        return build(postorder, 0 , postorder.size()-1 ,  inorder , 0 , inorder.size()-1 ,mp) ; 

    }
};