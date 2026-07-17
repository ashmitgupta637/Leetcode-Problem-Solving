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
    void levelsum(TreeNode* root , vector<int>&arr) {
        if(root == nullptr) return ; 
        queue<TreeNode*> q  ; 
        q.push(root) ; 
        while(!q.empty()) {
            int size = q.size() ; 
            int sum = 0 ; 

            for(int i = 0 ; i < size; i++) {
                TreeNode* node = q.front() ; 
                q.pop() ; 
                sum += node->val ; 
                if(node->left) q.push(node->left) ; 
                if(node->right) q.push(node->right) ; 

            }
            arr.push_back(sum) ; 
        }

    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> arr ; 
        levelsum(root , arr) ; 
        queue<TreeNode*> q ; 
        q.push(root) ; 
        root->val = 0 ; 
        int level = 0 ; 
        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                int childsum = 0;

                if (node->left)
                    childsum += node->left->val;

                if (node->right)
                    childsum += node->right->val;

                if (node->left) {
                    node->left->val = arr[level + 1] - childsum;
                    q.push(node->left);
                }

                if (node->right) {
                    node->right->val = arr[level + 1] - childsum;
                    q.push(node->right);
                }
            }

            level++;
        }
        return root ; 

    }
};