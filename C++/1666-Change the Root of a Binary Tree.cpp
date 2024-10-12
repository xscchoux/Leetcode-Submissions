/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

// Iterative
class Solution {
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        Node* curr = leaf;
        Node* prev = nullptr;

        while (curr != root) {
            if (curr->left != nullptr) {
                curr->right = curr->left;
            }
            // curr.left, curr.parent = curr.parent, prev
            curr->left = curr->parent;
            curr->parent = prev;
            // prev, curr = curr, curr.left
            prev = curr;
            curr = curr->left;
            if (curr->left == prev) {
                curr->left = nullptr;
            } else {
                curr->right = nullptr;
            }
        }
        root->parent = prev;
        return leaf;
    }
};


// Recusive
class Solution {
public:
    Node* dfs(Node* root, Node* curr, Node* prev = nullptr) {
        if (curr == root) {
            curr->parent = prev;
            return curr;
        }
        if (curr->left) {
            curr->right = curr->left;
        }

        Node* oldParent = curr->parent;
        if (oldParent->left == curr) {
            oldParent->left = nullptr;
        } else {
            oldParent->right = nullptr;
        }
        curr->parent = prev;
        if (prev != nullptr) prev->left = curr;  // note that prev can be nullptr
        curr->left = dfs(root, oldParent, curr);

        return curr;
    }
    Node* flipBinaryTree(Node* root, Node * leaf) {
        return dfs(root, leaf);
    }
};