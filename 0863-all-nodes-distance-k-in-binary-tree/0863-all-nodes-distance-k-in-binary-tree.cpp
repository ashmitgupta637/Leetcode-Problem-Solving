/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markparent(TreeNode* root , unordered_map<TreeNode* , TreeNode*> &parenttrack , TreeNode* target ) {
        queue<TreeNode*> q ; 
        q.push(root)  ;
        while(!q.empty()) {
            TreeNode* node = q.front() ; 
            q.pop() ; 
            if(node->left) {
                parenttrack[node->left] = node ; 
                q.push(node->left) ; 

            }
            if(node->right) {
                parenttrack[node->right] = node ; 
                q.push(node->right) ; 

            }
        }
    }
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parenttrack ; 
        markparent(root , parenttrack , target) ; 
        unordered_map<TreeNode* , bool> visited ; 
        queue<TreeNode*> q ; 
        visited[target] = true ; 
        q.push(target) ; 
        int curr_level = 0 ; 
        while(!q.empty()) {
            int size = q.size() ; 
            if(curr_level++ == k ) break; 
            for(int i = 0 ; i < size ; i++) {
                TreeNode* curr_node = q.front() ; 
                q.pop() ; 
                if(curr_node->left && !visited[curr_node->left]) {
                    q.push(curr_node->left) ;
                    visited[curr_node->left] = true ; 
                }
                if(curr_node->right && !visited[curr_node->right]) {
                    q.push(curr_node->right) ; 
                    visited[curr_node->right]  = true ; 
                }
                if(parenttrack[curr_node] && !visited[parenttrack[curr_node]]) {
                    q.push(parenttrack[curr_node]) ; 
                    visited[parenttrack[curr_node]] = true ; 
                }
            }
        }

        vector<int> result  ;
        while(!q.empty()) {
            TreeNode* node  = q.front() ; 
            q.pop()  ; 
            result.push_back(node->val) ; 

        }
        return result  ;

    }
};