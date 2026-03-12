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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int depthX = -1, depthY = -1;
        TreeNode* parentX = nullptr;
        TreeNode* parentY = nullptr;
        
        int depth = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Check children
                if (node->left) {
                    if (node->left->val == x) {
                        depthX = depth + 1;
                        parentX = node;
                    }
                    if (node->left->val == y) {
                        depthY = depth + 1;
                        parentY = node;
                    }
                    q.push(node->left);
                }
                
                if (node->right) {
                    if (node->right->val == x) {
                        depthX = depth + 1;
                        parentX = node;
                    }
                    if (node->right->val == y) {
                        depthY = depth + 1;
                        parentY = node;
                    }
                    q.push(node->right);
                }
            }
            depth++;
        }
        
        // Check cousins condition
        return (depthX == depthY) && (parentX != parentY);
    }
};