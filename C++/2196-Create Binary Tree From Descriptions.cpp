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
    TreeNode* dfs(unordered_map<int, vector<pair<int, int>>>& graph, int curr) {
        TreeNode* node = new TreeNode(curr);
        for (auto &[child, isLeft]:graph[curr]) {
            if (isLeft == 0) {
                node->right = dfs(graph, child);
            } else {
                node->left = dfs(graph, child);
            }
        }
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int, int>>> graph;
        unordered_set<int> parents, children;

        for (auto d:descriptions) {
            int root = d[0], child = d[1], isLeft = d[2];
            parents.insert(root);
            children.insert(child);
            if (isLeft) {
                graph[root].push_back({child, 1});
            } else {
                graph[root].push_back({child, 0});
            }            
        }

        int rootVal = -1;
        for (int p:parents) {
            if (!children.contains(p)) {
                rootVal = p;
                break;
            }
        }

        return dfs(graph, rootVal);
    }
};




// Clever two pass solution
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> hmap;
        unordered_set<int> childVal;
        for (auto &d:descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (!hmap.count(parent)) {
                hmap[parent] = new TreeNode(parent);
            }
            if (!hmap.count(child)) {
                hmap[child] = new TreeNode(child);
            }
            if (isLeft) {
                hmap[parent]->left = hmap[child];
            } else {
                hmap[parent]->right = hmap[child];
            }
            childVal.insert(child);
        }

        for (auto &d:descriptions) {
            int parent = d[0];
            if (!childVal.contains(parent)){
                return hmap[parent];
            }
        }

        return nullptr;
    }
};