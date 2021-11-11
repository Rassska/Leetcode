/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    
    Node* connect(Node* root) {
        
        q.push(root);
        if (root == nullptr) {
            return root;
        }
        
        while (!q.empty()) {
            
            uint32_t qSize = q.size();
            
            
            for (std::size_t i = 0; i < qSize; i++) {
                Node* tempNode = q.front();
                q.pop();
                
                if (i < qSize - 1) {
                    tempNode->next = q.front();
                }
                
                if (tempNode->left != nullptr) {
                    q.push(tempNode->left);
                } 
                if (tempNode->right != nullptr) 
                    q.push(tempNode->right);
            }
            
        }
        return root;
        
        
    }
    
private:
    std::queue<Node*> q;
};