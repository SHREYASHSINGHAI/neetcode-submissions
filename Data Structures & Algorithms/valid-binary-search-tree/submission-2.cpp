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
    bool bfs(TreeNode* root){
        queue<tuple<TreeNode*, long long , long long>>q;
        q.push({root,LLONG_MIN, LLONG_MAX});
        while(!q.empty()){

            auto[root, minval, maxval] = q.front();
            q.pop();
            if(root->val <= minval || root->val >= maxval){
                return false;
            }
            if(root->left != NULL){
                    q.push({root->left, minval, root->val});               
            }
            if(root->right != NULL){
                    q.push({root->right, root->val, maxval});
            }
            
        }
        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        return bfs(root);
    }
};
