class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int curr_lvl_size = q.size();

            for (int i = 0; i < curr_lvl_size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                
                if (i == curr_lvl_size - 1) {
                    result.push_back(curr->val);
                }

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
        }
        return result;
    }
};