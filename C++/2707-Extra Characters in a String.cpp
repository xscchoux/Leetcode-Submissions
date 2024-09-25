class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode (): isEnd(false) {
    }
};

class Solution {
public:
    void dfs(int ind, string& s, TrieNode* root, vector<int>& dp) {
        if (!root->children.contains(s[ind])) return;
        int currIdx = ind;
        while (ind>=0) {
            if (root->children.contains(s[ind])) {
                root = root->children[s[ind]];
            } else {
                break;
            }
            if (root->isEnd) {
                dp[ind] = max(dp[ind], dp[currIdx+1]+currIdx-ind+1);
            }
            ind--;
        }
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* root = new TrieNode();
        for (string d:dictionary) {
            TrieNode* node = root;
            for (int i=d.size()-1; i>=0; i--) {
                if (!node->children.contains(d[i])) {
                    node->children[d[i]] = new TrieNode();
                }
                node = node->children[d[i]];
            }
            node->isEnd = true;
        }
        int N = s.size();
        vector<int> dp(N+1, 0);  // dp[i]: number of used characters from index N-1 to i

        for (int i=N-1; i>=0; i--) {
            dfs(i, s, root, dp);
            dp[i] = max(dp[i], dp[i+1]);
        }


        return N - dp[0];
    }
};



// faster Trie solution
class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        explicit TrieNode():isEnd(false){
            std::fill(children, children +26 , nullptr);
        }
        virtual ~TrieNode(){ // this makes code even faster
            for(TrieNode* e : children) delete e;
        }
    };
    void dfs(int ind, string& s, TrieNode* root, vector<int>& dp) {
        if (root->children[s[ind]-'a'] == nullptr) return;
        int currIdx = ind;
        while (ind>=0) {
            if (root->children[s[ind]-'a'] != nullptr) {
                root = root->children[s[ind]-'a'];
            } else {
                break;
            }
            if (root->isEnd) {
                dp[ind] = max(dp[ind], dp[currIdx+1]+currIdx-ind+1);
            }
            ind--;
        }
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* root = new TrieNode();
        for (string d:dictionary) {
            TrieNode* node = root;
            for (int i=d.size()-1; i>=0; i--) {
                if (node->children[d[i]-'a'] == nullptr) {
                    node->children[d[i]-'a'] = new TrieNode();
                }
                node = node->children[d[i]-'a'];
            }
            node->isEnd = true;
        }
        int N = s.size();
        vector<int> dp(N+1, 0);  // dp[i]: number of used characters from index N-1 to i

        for (int i=N-1; i>=0; i--) {
            dfs(i, s, root, dp);
            dp[i] = max(dp[i], dp[i+1]);
        }


        return N - dp[0];
    }
};