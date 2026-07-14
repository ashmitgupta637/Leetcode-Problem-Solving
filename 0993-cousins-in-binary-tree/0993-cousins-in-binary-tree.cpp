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
    int depth(TreeNode* root , TreeNode* x) {
        if(root == x) return -1 ; 
        queue<pair<TreeNode* , int>> q ; 
        q.push({root , 0}) ; 
        while(!q.empty()) {
            TreeNode* node = q.front().first ; 
            int depth =  q.front().second ; 
            q.pop() ; 
            if(node == x) {
                return depth  ; 
            }
            if(node->left ) q.push({node->left ,  depth+1}) ; 
            if(node->right) q.push({node->right , depth+1}) ; 

        } 
        return -1 ; 



    }
    TreeNode* bfs(TreeNode* root , int x) {
        if(root== nullptr) return root ;  
        stack<TreeNode*> st   ; 
        st.push(root) ; 
        while(!st.empty()) {
            TreeNode* node = st.top() ; 
            st.pop() ; 
            if(node->val == x) {
                return node ; 
            }
            if(node->right) st.push(node->right) ; 
            if(node->left) st.push(node->left) ; 
        }
        return nullptr  ; 
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr) return false ; 
        unordered_map<TreeNode* , TreeNode*> parent ;
        stack<TreeNode*> st  ; 
        st.push(root)  ; 
        while(!st.empty()) {
            TreeNode* node =  st.top() ; 
            st.pop() ; 
            if(node->right) {
                parent[node->right] = node ; 
                st.push(node->right) ; 
            }
            if(node->left) {
                parent[node->left] = node ; 
                st.push(node->left) ; 
            }
        }

        TreeNode* node1 =  bfs(root, x) ; 
        TreeNode* node2 = bfs(root , y)  ; 
        if(parent[node1] == parent[node2]) return false;  
        if(depth(root , node1 ) != depth(root , node2)) return false ; 

        return true ; 

    }
};