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
    bool isSameTree(TreeNode* r1 , TreeNode* r2) { 
        if(r1 == nullptr && r2 == nullptr) {
            return true   ; 
        }
        if(r1 == nullptr || r2 == nullptr || r1->val != r2->val) {
            return false;  
        }
        
        bool lh = isSameTree(r1->left , r2->left) ; 
        bool rh = isSameTree(r1->right , r2->right) ; 

        return lh && rh  ; 


    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false ; 
        }
        queue<TreeNode*> q ; 
        q.push(root) ; 
        while(!q.empty()) {
            TreeNode* node= q.front() ; 
            q.pop() ; 
            if(isSameTree(node , subRoot)) {
                return true  ; 
            }
            if(node->left ) q.push(node->left)  ;
            if(node->right) q.push(node->right)  ; 

        }
        return false ; 
    }
};