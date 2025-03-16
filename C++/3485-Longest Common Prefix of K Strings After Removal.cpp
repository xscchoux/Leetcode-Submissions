class TrieNode {
public:
    TrieNode* children[26];
    int count;
    TrieNode(): count(0) {
        fill(children, children+26, nullptr);
    }
};

class Solution {
public:
    int N, k;
    unordered_map<int, int> cnt;
    set<int> existingLens;

    void addWord(string word, TrieNode* node) {
        int length = 0;
        for (char ch:word) {
            if (node->children[ch-'a'] == nullptr) {
                node->children[ch-'a'] = new TrieNode();
            }
            node = node->children[ch-'a'];
            node->count++;
            length++;
            if (node->count == k) {
                cnt[length]++;
                if (cnt[length] == 1) existingLens.insert(length);
            }
        }
    }

    void removeWord(string word, TrieNode* node) {
        int length = 0;
        for (char ch:word) {
            if (node->children[ch-'a'] == nullptr) {
                node->children[ch-'a'] = new TrieNode();
            }
            node = node->children[ch-'a'];
            node->count--;
            length++;
            if (node->count == k-1) {
                cnt[length]--;
                if (cnt[length] == 0) existingLens.erase(length);
            }
        }
    }

    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        this->N = words.size();
        this->k = k;
        TrieNode* root = new TrieNode();
        vector<int> res;

        for (int i=0; i<N; i++) {
            addWord(words[i], root);
        }

        for (int i=0; i<N; i++) {
            removeWord(words[i], root);

            if (existingLens.empty()) {
                res.push_back(0);
            } else {
                res.push_back(*existingLens.rbegin());
            }

            addWord(words[i], root);
        }

        return res;
    }
};