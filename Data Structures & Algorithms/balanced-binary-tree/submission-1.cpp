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
int height(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    int height_left = height(root->left);
    int height_right = height(root->right);
    return max(height_left, height_right)+1;
}
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return abs(leftHeight-rightHeight) <= 1 &&
               isBalanced(root->left) &&
               isBalanced(root->right);
    }
};
