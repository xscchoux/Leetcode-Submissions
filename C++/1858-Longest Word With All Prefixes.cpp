class TrieNode {
public:
    TrieNode* node;
    bool isEnd;
    string s;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isEnd(false) {
    }
};
class Solution {
private:
    string res = "";
    void dfs(TrieNode* node) {
        if (node->isEnd) {
            if ((node->s).size() > res.size()) {
                res = node->s;
            } else if ((node->s).size() == res.size()) {
                res = min(res, node->s);
            }
        }

        if (!node->isEnd) return;

        for (auto [key, node]:node->children) {
            dfs(node);
        }
    }
public:
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        root->isEnd = true;

        for (string word:words) {
            TrieNode* node = root;
            for (char w:word) {
                if (!node->children.contains(w)) {
                    TrieNode* nxt = new TrieNode();
                    node->children[w] = nxt;
                }
                node = node->children[w];
            }
            node->isEnd = true;
            node->s = word;
        }
        dfs(root);

        return res;
    }
};



// faster trie solution
class Solution {
private:
    string res = "";
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        string s;
        explicit TrieNode():isEnd(false){
            std::fill(children, children +26 , nullptr);
        }
        virtual ~TrieNode(){ // this makes code even faster
            for(TrieNode* e : children) delete e;
        }
    };
    void dfs(TrieNode* node) {
        if (node->isEnd) {
            if ((node->s).size() > res.size()) {
                res = node->s;
            } else if ((node->s).size() == res.size()) {
                res = min(res, node->s);
            }
        }

        if (!node->isEnd) return;

        for (auto node:node->children) {
            if (node == nullptr) continue;
            dfs(node);
        }
    }
public:

    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        root->isEnd = true;

        for (string word:words) {
            TrieNode* node = root;
            for (char w:word) {
                if (node->children[w-'a'] == nullptr) {
                    TrieNode* nxt = new TrieNode();
                    node->children[w-'a'] = nxt;
                }
                node = node->children[w-'a'];
            }
            node->isEnd = true;
            node->s = word;
        }
        dfs(root);

        return res;
    }
};