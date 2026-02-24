class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        queue<TreeNode*> queue;
        queue.push(root->left);
        queue.push(root->right);
        
        while (!queue.empty()) {
            TreeNode* left = queue.front();
            queue.pop();
            TreeNode* right = queue.front();
            queue.pop();
            
          
            if (left == nullptr && right == nullptr) {
                continue;
            }
            
         
            if (left == nullptr || right == nullptr) {
                return false;
            }
            
          
            if (left->val != right->val) {
                return false;
            }
           
            queue.push(left->left);
            queue.push(right->right);
            queue.push(left->right);
            queue.push(right->left);
        }
        
        return true;
    }
}
;