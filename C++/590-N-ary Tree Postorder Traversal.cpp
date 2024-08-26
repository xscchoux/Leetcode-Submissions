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

// Recursive, trivial
class Solution {
public:
    vector<int> res;
    void dfs(Node* node) {
        if (node == nullptr) return;
        for (auto nxt:node->children) {
            dfs(nxt);
        }
        res.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        dfs(root);
        return res;
    }
};


// Iterative (Explicit Reversal)
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr) return res;

        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* curr = stk.top();
            stk.pop();
            res.push_back(curr->val);
            for (auto nxt:curr->children) {
                stk.push(nxt);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};



// Iterative without reversal (hard and not faster)
class Solution {
private:
    struct NodePair {
        Node* node;
        bool visited;
        NodePair(Node* n, bool v): node(n), visited(v) {}
    };
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<NodePair> stk;
        stk.push({root, false});

        while (!stk.empty()) {
            auto currPair = stk.top();
            stk.pop();
            if (currPair.visited) {
                res.push_back(currPair.node->val);
            } else {
                currPair.visited = true;
                stk.push(currPair);

                vector<Node*> &children = currPair.node->children;
                for (int i=children.size()-1; i>=0; i--) {
                    stk.push({children[i], false});
                }
            }
        }

        return res;
    }
};