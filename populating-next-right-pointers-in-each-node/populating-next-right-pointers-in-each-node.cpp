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
        if (root == nullptr) {
            return nullptr;
        }
        q.push(root);
        q.push(nullptr);
        
        while (!q.empty()) {
            Node* currNode = q.front(); q.pop();
            
            if (currNode != nullptr) {
                currNode->next = q.front();
                if (currNode->left != nullptr) {
                    q.push(currNode->left);
                }
                if (currNode->right != nullptr) {
                    q.push(currNode->right);
                }
            } else if (q.size() > 1){
                q.push(nullptr);
            } else {
                break;
            }
        }
        return root;
        
    }
    
private:
    std::queue<Node*> q;
};