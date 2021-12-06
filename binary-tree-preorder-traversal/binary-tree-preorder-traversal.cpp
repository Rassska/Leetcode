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
        std::stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        
        while (!st.empty()) {
            TreeNode* tempNode = st.top(); 
            st.pop();
            treePreorderTraversal.push_back(tempNode->val);
            if (tempNode->right != nullptr) {
                st.push(tempNode->right);
            }
            if (tempNode->left != nullptr) {
                st.push(tempNode->left);
            }
        }
        
        return treePreorderTraversal;
    }
private:
    std::vector<int> treePreorderTraversal;
};