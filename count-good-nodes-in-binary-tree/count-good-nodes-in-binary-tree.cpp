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
    
    void goodNodesHelper (TreeNode* root, int maxValue) {
        
        if (root == nullptr) {
            return ;
        } else {
            if (maxValue <= root->val) {
                maxValue = root->val;
                ans++;
            }
            goodNodesHelper(root->left, maxValue);
            goodNodesHelper(root->right, maxValue);
        }
    }
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        maxValue = root -> val;
        goodNodesHelper(root->left, maxValue);
        goodNodesHelper(root->right, maxValue);
        return ans;
        
    }
private:
    std::size_t ans = 1;
    int maxValue = std::numeric_limits<int>::min();
        
};