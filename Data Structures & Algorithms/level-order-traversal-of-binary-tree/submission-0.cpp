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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> result;
        if(root == nullptr){
            return {};
        }

        while(!q.empty()){
            vector<int> curr_lvl;
            int level_size=q.size();
            for(int i = 0; i < level_size; i++){
                TreeNode* curr = q.front();
                q.pop();
                curr_lvl.push_back(curr->val);

                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }

            }
            result.push_back(curr_lvl);
        }
        return result;
    }
};
