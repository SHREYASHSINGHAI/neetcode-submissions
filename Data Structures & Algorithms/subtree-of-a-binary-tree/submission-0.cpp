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
bool flag = false;
    bool isSameTree(TreeNode* root, TreeNode* subroot){
        if(root == nullptr || subroot == nullptr){
            return root == subroot;
        }
        bool isleftsame = isSameTree(root->left, subroot->left);
        bool isrightsame = isSameTree(root->right, subroot -> right);
        return isleftsame && isrightsame && root->val == subroot->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root == nullptr){
            return false;
        }
        if(isSameTree(root,subroot)){
            return true;            
        }
            return isSubtree(root->left,subroot) || isSubtree(root->right, subroot);
    }
};
