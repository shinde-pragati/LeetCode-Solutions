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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;

        }
        stack<pair<TreeNode*, int>> stack;
        stack.push({root,1});
        int maxDepth = 0;
        while (!stack.empty()) {
            auto [node,depth] = stack.top();
            stack.pop();
            maxDepth = max(maxDepth, depth);
            if (node->left != nullptr) {
                stack.push({node->left, depth + 1});
            }
            if (node->right != nullptr) {
                stack.push({node->right, depth + 1});
            }
        }
        return maxDepth;
    }
};