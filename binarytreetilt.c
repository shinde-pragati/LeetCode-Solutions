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
    int findTilt(TreeNode* root) {
        int totalTilt = 0;
        calculateSum(root, totalTilt);
        return totalTilt;
    }
    private:
    int calculateSum(TreeNode* node, int& totalTilt) {
        if (node == nullptr) return 0;

        int leftSum = calculateSum(node->left, totalTilt);
        int rightSum = calculateSum(node->right, totalTilt);
        totalTilt += abs(leftSum - rightSum);
        return node->val + leftSum + rightSum;
    }
};