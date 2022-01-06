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
    
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return preorder;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* currNode = st.top(); st.pop();
            preorder.push_back(currNode->val);
            if (currNode->right != nullptr) {
                st.push(currNode->right);
            }
           
            if (currNode->left != nullptr) {
                st.push(currNode->left);
            }
            
        }
        return preorder;
        
        
    }
    
private:
    std::stack<TreeNode*> st;
    std::vector<int> preorder;
};