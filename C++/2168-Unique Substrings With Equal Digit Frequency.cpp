class Solution {
struct TrieNode {
    TrieNode* children[10];
    bool isVisited;
    TrieNode() :isVisited(false) {
        fill(begin(children), end(children), nullptr);
        // fill(begin(children), begin(children)+10, nullptr); <- alternative
    }
};
public:
    int equalDigitFrequency(string s) {
        int res = 0, N = s.size();
        TrieNode* root = new TrieNode();
        
        for (int start=0; start<N; start++) {
            int maxCount = 0, diffCount = 0;
            vector<int> cnt(26, 0);
            TrieNode* node = root;
            for (int curr = start; curr < N; curr++) {
                if (cnt[s[curr]-'0'] == 0) {
                    diffCount++;
                }
                cnt[s[curr]-'0']++;
                maxCount = max(cnt[s[curr]-'0'], maxCount);
                if (node->children[s[curr]-'0'] == nullptr) {
                    node->children[s[curr]-'0'] = new TrieNode();
                }

                node = node->children[s[curr]-'0'];
                if (maxCount*diffCount == curr-start+1 && node->isVisited == false) {
                    res++;

                    node->isVisited = true;
                }
            }
        }

        return res;
    }
};