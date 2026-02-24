class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        
       
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, targetSum - root->val});
        
        while (!stack.empty()) {
            auto [node, remainingSum] = stack.top();
            stack.pop();
            
           
            if (node->left == nullptr && node->right == nullptr && remainingSum == 0) {
                return true;
            }
            
            if (node->left != nullptr) {
                stack.push({node->left, remainingSum - node->left->val});
            }
            if (node->right != nullptr) {
                stack.push({node->right, remainingSum - node->right->val});
            }
        }
        
        return false;
    }
};