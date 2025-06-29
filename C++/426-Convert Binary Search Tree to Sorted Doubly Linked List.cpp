/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// first AC, but this is not an in-place transformation
class Solution {
public:
    Node* head = new Node(-1);
    Node* curr = head;
    void traversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        traversal(node->left);
        Node* newNode = new Node(node->val);
        curr->right = newNode;
        newNode->left = curr;
        curr = curr->right;
        traversal(node->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return root;
        traversal(root);
        Node* first = head->right;
        curr->right = first;
        first->left = curr;

        return first;
    }
};


// in-place transformation
class Solution {
public:
    Node* first = nullptr;
    Node* last = nullptr;

    void traversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        traversal(node->left);
        if (first == nullptr) {
            first = node;
        } else {
            node->left = last;
            last->right = node;   
        }
        last = node;
        traversal(node->right);
        
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return root;
        traversal(root);
        last->right = first;
        first->left = last;

        return first;
    }
};