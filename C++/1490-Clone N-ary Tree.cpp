/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node) {
        Node* copyNode = new Node(node->val);
        for (auto nxt:node->children) {
            copyNode->children.push_back(dfs(nxt));
        }

        return copyNode;
    }
    Node* cloneTree(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }     
        return dfs(root);
    }
};