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
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        isUnivalueTree(root);
        return ans;
        
    }
    
    bool isUnivalueTree (TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            ans++;
            return true;
        }
        bool isUnival = true;
        if (root->left != nullptr) {
            isUnival = isUnivalueTree(root->left) && isUnival && root->left->val == root->val;
        }
        if (root->right != nullptr) {
            isUnival = isUnivalueTree(root->right) && isUnival && root->right->val == root->val;
        }
        
        if (!isUnival) return false;
        
        ans++;
        return true;
       
        
        
        
    }
private:
    int ans = 0;
};