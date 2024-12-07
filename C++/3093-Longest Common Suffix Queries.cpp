// map (based on a balanced binary tree, typically std::map) has a smaller memory footprint per element because:
// It does not store a hash table.
// It does not require extra memory for managing buckets or resizing.

// unordered_map uses a hash table under the hood:
// Each element is stored in a bucket, with additional memory for hash computations and collision resolution.
// This overhead can significantly increase memory usage, especially when you have a large number of nodes (as in this Trie).

class Solution {
    struct TrieNode {
        map<char, TrieNode*> children;
        int idx;
        explicit TrieNode():idx(-1) {
        }
        virtual ~TrieNode(){ // this makes code even faster
            for(auto e: children) delete e.second;
        }
    };
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        int minIdx = 0;

        for (int k = 0; k < wordsContainer.size(); k++) {
            TrieNode* node = root;
            auto &word = wordsContainer[k];
            for (int i=word.size()-1; i>=0; i--) {
                if (node->children[word[i]] == nullptr) {
                    node->children[word[i]] = new TrieNode();
                }
                node = node->children[word[i]];
                if (node->idx == -1) {
                    node->idx = k;
                } else if (wordsContainer[node->idx].size() > wordsContainer[k].size()) {
                    node->idx = k;
                }

            }
            if (wordsContainer[k].size() < wordsContainer[minIdx].size()) {
                minIdx = k;
            }
        }

        vector<int> res;
        for (auto &word:wordsQuery) {
            TrieNode* node = root;
            int currIdx = minIdx;
            for (int i=word.size()-1; i>=0; i--) {
                if (node->children[word[i]] == nullptr) break;
                node = node->children[word[i]];
                currIdx = node->idx;
            }

            res.push_back(currIdx);
        }

        return res;
    }
};