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
using namespace std ; 
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(root == nullptr) return root ; 

        if(depth == 1 ) {
            TreeNode * nroot = new TreeNode(val) ; 
            nroot->left = root ; 
            return nroot ; 
        }

        queue<TreeNode*> q ; 
        q.push(root) ; 
        
        int currdepth = 1 ; 
        while(!q.empty()){
            int size = q.size() ;
            
            if(currdepth == depth-1){
                for(int i = 0 ; i < size ;  i++) {
                    TreeNode* node = q.front() ; 
                    q.pop() ;
                    TreeNode * templeft = node->left ; 
                    TreeNode * tempright = node->right   ; 


                    TreeNode* leftnode = new TreeNode(val) ; 
                    TreeNode* rightnode = new TreeNode(val) ; 

                    node->left = leftnode ; 
                    node->right  = rightnode ; 
                    leftnode->left = templeft ;

                    rightnode->right =  tempright ; 

                    
                }
                break ; 
            }
            for(int i =0 ; i< size ; i++){
                TreeNode* node  =  q.front()  ; 
                q.pop() ; 

                if(node->left) {
                    q.push(node->left) ; 

                }
                if(node->right) {
                    q.push(node->right) ; 
                }

            }
            currdepth++ ; 
            
        }

        return root  ; 
        
    }
};