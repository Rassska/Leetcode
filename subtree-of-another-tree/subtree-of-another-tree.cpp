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
    
    std::hash<string> hash_str;
    
    long long hashing(TreeNode* nd){
        if(nd==NULL)
            return LONG_MAX;
        
        long long left_hash = hashing(nd->left);
        long long right_hash = hashing(nd->right);
        
        string to_hash = to_string(left_hash) + to_string(nd->val) + to_string(right_hash);
        long long nd_hash = hash_str(to_hash);
        return nd_hash;
    }
    
    long long checkSub(TreeNode* nd, long long &hashSub, bool &res){
        if(nd==NULL)
            return LONG_MAX;
        
        long long left_hash = checkSub(nd->left, hashSub, res);
        long long right_hash = checkSub(nd->right, hashSub, res);
        
        string to_hash = to_string(left_hash) + to_string(nd->val) + to_string(right_hash);
        long long nd_hash = hash_str(to_hash);
        
        if(hashSub == nd_hash)
            res = true;
        
        return nd_hash;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        long long hashSub = hashing(subRoot);
        bool res = false;
        checkSub(root, hashSub, res);
        return res;
    }
    
};