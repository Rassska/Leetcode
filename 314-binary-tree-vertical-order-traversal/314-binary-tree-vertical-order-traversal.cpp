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
    
    void dfs (TreeNode* root, int currLineNumber = 1000) {
        if (!root) return ;
        
        if (root->left) {
            nodesTemp[currLineNumber - 1].push_back({nodesLayerInfo[root->left], root->left});
            dfs(root->left, currLineNumber - 1);
        }
        if (root->right) {
            nodesTemp[currLineNumber + 1].push_back({nodesLayerInfo[root->right], root->right});
            dfs(root->right, currLineNumber + 1);
        }
        
        
    }
    void layerSort (TreeNode* root) {
        if (!root) return ;
        std::queue<TreeNode*> q;
        q.push(root);
        nodesLayerInfo[root] = 0;
        
        while(!q.empty()) {
            TreeNode* currNode = q.front(); q.pop();
            
            if (currNode->left) {
                q.push(currNode->left);
                nodesLayerInfo[currNode->left] = nodesLayerInfo[currNode] + 1;
            }
            if (currNode->right) {
                q.push(currNode->right);
                nodesLayerInfo[currNode->right] = nodesLayerInfo[currNode] + 1;
            }
        }
        
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return nodes;
        
        nodesTemp.resize(2000);
        layerSort(root);
        nodesTemp[1000].push_back({0, root});
        dfs(root);
        
        for (std::size_t i = 0; i < nodesTemp.size(); i++) {
            if (!nodesTemp[i].empty()) {
                std::sort(nodesTemp[i].begin(), nodesTemp[i].end());
            }
        }
        
        for (std::size_t i = 0; i < nodesTemp.size(); i++) {
            std::vector<int> currLineNodes;
            for (std::size_t j = 0; j < nodesTemp[i].size(); j++) {
                currLineNodes.push_back(nodesTemp[i][j].second->val);
            }
            if (currLineNodes.size() != 0) 
                nodes.push_back(currLineNodes);
        }
        return nodes;
        
        
        
        
    }
private:
    std::vector<std::vector<int>> nodes;
    std::vector<std::vector<std::pair<int, TreeNode*>>> nodesTemp;
    std::unordered_map<TreeNode*, int> nodesLayerInfo;
   
};