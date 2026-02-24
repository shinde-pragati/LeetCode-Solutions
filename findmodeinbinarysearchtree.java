/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    private:vector<int>result;
    int maxCount = 0;
    int currentCount = 0;TreeNode*prev=nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        
        if (prev && root->val == prev->val) {
            currentCount++;
        } else {
            currentCount = 1;
        }
        
        if (currentCount > maxCount) {
            maxCount = currentCount;
            result.clear();
            result.push_back(root->val);
        } else if (currentCount == maxCount) {
            result.push_back(root->val);
        }
        
        prev = root;
        
        inorder(root->right);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
}
;