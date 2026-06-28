/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

// First AC
class Solution {
public:
    unordered_map<int, NodeCopy*> idx2Node;
    unordered_map<Node*, int> node2Idx;
    NodeCopy* dfs(int& idx, Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        idx2Node[idx] = new NodeCopy(node->val);
        node2Idx[node] = idx;
        int currIdx = idx;
        if (node->left != nullptr) {
            idx++;
            idx2Node[currIdx]->left = dfs(idx, node->left);
        }
        if (node->right != nullptr) {
            idx++;
            idx2Node[currIdx]->right = dfs(idx, node->right);
        }
        return idx2Node[currIdx];
    }
    void dfs2(int& idx, Node* node) {
        if (node->random != nullptr) {
            idx2Node[idx]->random = idx2Node[node2Idx[node->random]];
        }
        
        if (node->left != nullptr) {
            idx++;
            dfs2(idx, node->left);
        }
        if (node->right != nullptr) {
            idx++;
            dfs2(idx, node->right);
        }
    }

    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        int idx = 0;
        NodeCopy* res = dfs(idx, root);
        idx = 0;
        dfs2(idx, root);

        return idx2Node[0];
    }
};



// 1-pass DFS
class Solution {
public:
    unordered_map<Node*, NodeCopy*> hmap;
    NodeCopy* dfs(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (hmap.contains(node)) {
            return hmap[node];
        }

        hmap[node] = new NodeCopy(node->val);

        hmap[node]->left = dfs(node->left);
        hmap[node]->right = dfs(node->right);
        hmap[node]->random = dfs(node->random);

        return hmap[node];
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        return dfs(root);
    }
};