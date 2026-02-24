class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        } 
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};