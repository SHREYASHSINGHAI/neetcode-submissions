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
int maxdia = 0;
    int calculate(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
    
        int leftheight = calculate(root->left);
        int rightheight = calculate(root->right);
        maxdia = max(leftheight + rightheight, maxdia);
        return max(leftheight, rightheight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxdia = 0;
        calculate(root);
        return maxdia ;
    }
};
