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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInorder(root, sum);
        return root;
    }
    
private:
    void reverseInorder(TreeNode* node, int& sum) {
        if (!node) return;
        
        // Traverse right subtree first (greater values)
        reverseInorder(node->right, sum);
        
        // Update current node value
        sum += node->val;
        node->val = sum;
        
        // Traverse left subtree
        reverseInorder(node->left, sum);
    }
};