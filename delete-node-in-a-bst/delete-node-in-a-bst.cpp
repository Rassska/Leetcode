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
    
    int successor (TreeNode* root) {
        root = root->right;
        while (root->left != nullptr) {
            root = root->left;
        }
        return root->val;
    }
    int predecessor (TreeNode* root) {
        root = root->left;
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        } 
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->right == nullptr && root->left == nullptr && root->val == key) {
                root = nullptr;
            } else if (root->right != nullptr) {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            } else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        
        return root;
        
        
        
     
    }
    
private: 
    
};