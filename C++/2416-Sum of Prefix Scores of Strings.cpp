class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int cnt;
    TrieNode (): cnt(0){
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int N = words.size();
        TrieNode* root = new TrieNode();
        for (string &word:words) {
            TrieNode* node = root;
            for (char w:word) {
                if (!node->children.contains(w)) {
                    node->children[w] = new TrieNode();
                }
                node = node->children[w];
                node->cnt++;
            }
        }

        vector<int> res(N);
        for (int i=0; i<N; i++) {
            TrieNode* node = root;
            for (char w:words[i]) {
                node = node->children[w];
                res[i] += node->cnt;
            }
        }

        return res;
    }
};



// much faster
class Solution {
public:
struct TrieNode {
    TrieNode* children[26];
    int cnt;
    explicit TrieNode():cnt(0){
        std::fill(children, children +26 , nullptr);
    }
    virtual ~TrieNode(){ // this makes code even faster
        for(TrieNode* e : children) delete e;
    }
};
    vector<int> sumPrefixScores(vector<string>& words) {
        int N = words.size();
        TrieNode* root = new TrieNode();
        for (string &word:words) {
            TrieNode* node = root;
            for (char w:word) {
                if (node->children[w-'a'] == nullptr) {
                    node->children[w-'a'] = new TrieNode();
                }
                node = node->children[w-'a'];
                node->cnt++;
            }
        }

        vector<int> res(N);
        for (int i=0; i<N; i++) {
            TrieNode* node = root;
            for (char w:words[i]) {
                node = node->children[w-'a'];
                res[i] += node->cnt;
            }
        }
        return res;
    }
};