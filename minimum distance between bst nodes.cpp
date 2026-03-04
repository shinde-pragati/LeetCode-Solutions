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
    int minDiffInBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        
        int minDiff = INT_MAX;
        for (int i = 1; i < values.size(); i++) {
            minDiff = min(minDiff, values[i] - values[i-1]);
        }
        
        return minDiff;
    }
    
private:
    void inorder(TreeNode* node, vector<int>& values) {
        if (!node) return;
        
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }
};