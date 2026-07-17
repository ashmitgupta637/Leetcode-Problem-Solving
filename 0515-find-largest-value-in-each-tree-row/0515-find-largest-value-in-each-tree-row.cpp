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
    vector<int> largestValues(TreeNode* root) {
        vector<int> m  ; 
        if(root == nullptr) {
            return m;
        }
        queue<TreeNode*> q ; 
        q.push(root) ; 
        while(!q.empty()) {
            vector<int> level  ; 
            int size = q.size() ; 
            for(int i =  0 ; i < size ; i++ ) {
                TreeNode* node = q.front() ; 
                q.pop() ; 
                level.push_back(node->val) ; 
                if(node->left) q.push(node->left) ; 
                if(node->right) q.push(node->right) ; 
            }
            int maxi  =  level[0] ; 
            for(int i = 0 ; i< level.size() ; i++) {
                if(level[i] > maxi) {
                    maxi = level[i] ; 
                }
            }
            m.push_back(maxi) ; 
        }
        return  m ; 
    }
};