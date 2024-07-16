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
    void createMap(unordered_map<int, vector<pair<int, char>>>& graph, TreeNode* node) {
        if (node == nullptr) return;
        if (node->left != nullptr) {
            graph[node->val].push_back({node->left->val, 'L'});
            graph[node->left->val].push_back({node->val, 'U'});
            createMap(graph, node->left);
        }
        if (node->right != nullptr) {
            graph[node->val].push_back({node->right->val, 'R'});
            graph[node->right->val].push_back({node->val, 'U'});
            createMap(graph, node->right);
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int, vector<pair<int, char>>> graph;
        createMap(graph, root);

        queue<int> q;
        q.push(startValue);
        unordered_set<int> visited;
        unordered_map<int, pair<int, char>> pathTracker;

        int step = 0;
        while (!q.empty()) {
            int length = q.size();
            while(length-- > 0) {
                int curr = q.front();
                visited.insert(curr);
                q.pop();
                if (curr == destValue) break;
                for (auto &[nxt, letter]:graph[curr]) {
                    if (!visited.contains(nxt)) {
                        pathTracker[nxt] = {curr, letter}; 
                        q.push(nxt);
                    }
                }
            }
            step++;
        }

        string res = "";
        while (destValue != startValue) {
            auto [prev, letter] = pathTracker[destValue];
            res += letter;
            destValue = prev;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};




// Use LCA
class Solution {
public:
    bool getPath(TreeNode* LCA, int target, string& path) {
        if (LCA->val == target) return true;
        if (LCA->left != nullptr) {
            path.append("L");
            if (getPath(LCA->left, target, path)) return true;
            path.pop_back();
        }
        if (LCA->right != nullptr) {
            path.append("R");
            if (getPath(LCA->right, target, path)) return true;
            path.pop_back();
        }
        return false;
    }
    TreeNode* findLCA(TreeNode* node, int startValue, int destValue) {
        if (node == nullptr || node->val == startValue || node->val == destValue) return node;
        
        TreeNode* leftNode = findLCA(node->left, startValue, destValue);
        TreeNode* rightNode = findLCA(node->right, startValue, destValue);

        if (leftNode != nullptr && rightNode != nullptr) return node;
        return (leftNode == nullptr)?rightNode:leftNode;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = findLCA(root, startValue, destValue);
        
        string startPath, destPath;  // path from LCA to start && path from LCA to dest
        getPath(LCA, startValue, startPath);
        getPath(LCA, destValue, destPath);

        string res;
        res.append(startPath.length(), 'U');  // note that 'U' should be a char here
        res.append(destPath);

        return res;
    }
};