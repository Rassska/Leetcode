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
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } 
        dfs(root, root->val);
        return longestUniPath;
        
    }
    
    int dfs (TreeNode* root, int rootValue) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left, root->val);
        int right = dfs(root->right, root->val);
        
        longestUniPath = std::max(longestUniPath, left + right);
        if (rootValue == root->val)
            return std::max(left, right) + 1;
        return 0;
        
    }
private:
    int longestUniPath = 0;
    
};