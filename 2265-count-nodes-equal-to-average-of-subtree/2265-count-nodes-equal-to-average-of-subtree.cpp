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
    int cnt = 0 ; 
    int count_Subtree(TreeNode* root) {
        if(root == nullptr) return 0 ; 

        int left_cnt = count_Subtree(root->left ) ; 
        int right_cnt = count_Subtree(root->right) ; 

        return left_cnt + right_cnt + 1 ; 

    }
    int f(TreeNode* root  , vector<pair<int,int>>& average){
        if(root == nullptr) return 0  ; 
         
        int sum_left = f(root->left , average) ; 

        int sum_right =  f(root->right  , average) ; 
        
        int n = count_Subtree(root) ; 
        int sum = sum_left + sum_right + root->val;
        int avg = sum/n ; 
        average.push_back({root->val  , avg }) ; 

        return sum ;  

    }
    

public:
    int averageOfSubtree(TreeNode* root) {
        vector<pair<int,int>> average; 
        f(root , average)  ; 

        for(auto x : average) {
            if(x.first == x.second){
                cnt++ ; 
            }
        }

        return cnt ; 
    }
};