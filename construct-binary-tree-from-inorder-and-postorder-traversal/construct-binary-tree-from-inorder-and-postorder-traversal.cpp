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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        
        int tempIdx = 0;
        this->postIdx = postorder.size() - 1;
        for (auto curr : inorder) {
            mapIdx[curr] = tempIdx++;
        }
        
        return constructTree(0, inorder.size() - 1);
        
    }
    
    TreeNode* constructTree(int leftIdx, int rightIdx) {
        if (leftIdx > rightIdx) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[postIdx--]);
        int inRootIdx = mapIdx[root->val];
        
        root->right = constructTree(inRootIdx + 1, rightIdx);
        root->left = constructTree(leftIdx, inRootIdx - 1);
        
        return root;
        
    }
private:
    std::unordered_map<int, int> mapIdx;
    std::vector<int> inorder, postorder;
    int postIdx;
};