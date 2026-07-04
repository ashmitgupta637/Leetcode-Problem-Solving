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
    bool helper(TreeNode* root , vector<TreeNode*>& st , int startValue){
        if(root == nullptr) {
            return false ; 
        }
        st.push_back(root) ;; 
        if(root->val == startValue) {
            return true ; 
        }

        if(helper(root->left , st , startValue) || helper(root->right , st ,startValue)) {
            return true  ; 
        }

        st.pop_back() ; 
        return false; 


    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s  = "" ;  
        if(root == nullptr) return s; 
        vector<TreeNode*>  arr1  ; 
        vector<TreeNode*> arr2 ; 
        helper(root , arr1 , startValue) ; 
        helper(root , arr2 , destValue) ;
        TreeNode* common = root ;  
        int i = 0;
        while (i < arr1.size() && i < arr2.size() && arr1[i] == arr2[i]) {
            common = arr1[i];
            i++;
        }
        int k = arr1.size() - i;
        s.append(k , 'U' ) ; 
        
        for(int j = i; j < arr2.size(); j++) {

            TreeNode* parent = arr2[j - 1];
            TreeNode* child  = arr2[j];

            if(parent->left == child){
                s += 'L';
            }else{
                s += 'R';
            }
                
        }
        return s ; 

    }
};