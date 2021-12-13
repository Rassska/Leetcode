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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        
        std::size_t tempIndex = 0;
        for (auto currVal : inorder) {
            inorderIndexHashMap[currVal] = tempIndex++;
        }
        
        return constructTree(0, preorder.size() - 1);
    }
    
    TreeNode* constructTree(int inorderLeft, int inorderRight) {
        if (inorderLeft > inorderRight) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[indexPreorder++]);
        std::size_t rootPos = inorderIndexHashMap[root->val];
        
        root->left = constructTree(inorderLeft, rootPos - 1);
        root->right = constructTree(rootPos + 1, inorderRight);
        return root;
    }
    
private:
    std::vector<int> preorder;
    std::vector<int> inorder;
    std::size_t indexPreorder = 0;
    std::unordered_map<int, int> inorderIndexHashMap;
};