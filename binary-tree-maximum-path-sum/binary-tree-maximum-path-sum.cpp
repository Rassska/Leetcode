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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxPathSumm;
    }
    
    int dfs (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int x = dfs(root->left);
        int y = dfs(root->right);
        maxPathSumm = std::max(maxPathSumm, x + y + root->val);
        return std::max(root->val + std::max(x, y), 0);
        
    }
private: 

    int maxPathSumm = INT_MIN;
};