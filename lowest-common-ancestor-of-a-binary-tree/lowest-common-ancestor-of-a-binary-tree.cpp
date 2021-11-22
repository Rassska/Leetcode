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
        findLCA(root, p, q);
        return lca;
    }
    
    bool findLCA (TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        bool x = findLCA(root->left, p, q);
        bool y = findLCA (root->right, p, q);
        bool curr = root == q || root == p;
        
        if ((x && y) || (curr && x) || (curr && y)) {
            lca = root;
        }
        return x || y || curr;
        
        
    }
private:
    TreeNode* lca = nullptr;
};