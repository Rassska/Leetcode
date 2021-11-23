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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> rightViewNodes;
        
        std::queue<TreeNode*> currLevel, nextLevel;
        nextLevel.push(root);
        
        while (!nextLevel.empty()) {
            
            currLevel = nextLevel;
            nextLevel = std::queue<TreeNode*>();
            
            while (!currLevel.empty()) {
                TreeNode* currNode = currLevel.front(); currLevel.pop();
                if (currNode != nullptr) {
                    if (currNode->left != nullptr)
                        nextLevel.push(currNode->left);
                    if (currNode->right)
                        nextLevel.push(currNode->right);
                    if (currLevel.empty()) {
                        rightViewNodes.push_back(currNode->val);
                    }
                }
                
            }
            
            
        }
        return rightViewNodes;
    }
};