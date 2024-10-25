struct TrieNode {
    unordered_map<string, TrieNode*> children;
    string curr;
    ~TrieNode() {
        for (auto& [key, child] : children) {
            delete child;
        }
    }
};
class Solution {
public:
    vector<string> res;
    void dfs(TrieNode* node) {
        for (auto [key, nxt]:node->children) {
            if (nxt != nullptr && !(nxt->curr).empty()) {
                res.push_back(nxt->curr);
            } else {
                dfs(nxt);
            }
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode* root = new TrieNode();
        for (string s:folder) {
            TrieNode* node = root;
            string key;
            for (char c:s) {
                if (c != '/') {
                    key += c;
                } else {
                    if (!node->children.contains(key)) {
                        node->children[key] = new TrieNode();
                    }
                    node = node->children[key];
                    key = "";
                }
            }
            if (node->children[key] == nullptr) {
                node->children[key] = new TrieNode();
            }
            node = node->children[key];
            node->curr = s;
        }

        dfs(root);
        return res;
    }
};