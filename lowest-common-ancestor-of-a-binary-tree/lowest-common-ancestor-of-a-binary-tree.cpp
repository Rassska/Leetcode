/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfs(root, p, q);
        return lca;
    }
    
    bool dfs (TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        
        
        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);
        
        int mid = (root == p || root == q);
        
        if (right + mid + left >= 2) {
            lca = root;
        }
        return (mid + left + right > 0);
    }
private: 
    TreeNode* lca = nullptr;

};