// TLE in C++
class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int N = target.size();
        vector<int> dp(N+1, INT_MAX/2);
        dp[0] = 0;
        unordered_map<string, int> hmap;
        
        for (int i=0; i<words.size(); i++) {
            if (hmap.contains(words[i])) {
                hmap[words[i]] = min(hmap[words[i]], costs[i]);
            } else {
                hmap[words[i]] = costs[i];
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=i; j>=0; j--) {
                string substr = target.substr(j, i-j+1);
                if (hmap.contains(substr)) {
                    dp[i+1] = min(dp[i+1], hmap[substr] + dp[j]);
                }
            }
        }
        return (dp.back() < INT_MAX/2?dp.back():-1);
    }
};



// Use Trie, O(target length * words length)
class TrieNode {
public:
    int cost = INT_MAX;
    TrieNode* ch[26] = {};

    void insert(TrieNode* curr, string& word, int c) {
        for (char w:word) {
            if (curr->ch[w-'a'] == nullptr) {
                curr->ch[w-'a'] = new TrieNode();
            }
            curr = curr->ch[w-'a'];
        }
        curr->cost = min(curr->cost, c);
    }
};

class Solution {
public:
    int N;
    TrieNode* root;
    int dfs(int ind, string& target, vector<int>& dp, TrieNode* curr) {
        if (ind == N) return 0;
        if (dp[ind] != INT_MAX/2) return dp[ind];

        int currCost = INT_MAX/2;
        int tmpInd = ind;
        while (tmpInd < N) {
            if (curr->ch[target[tmpInd]-'a'] == nullptr) break;
            curr = curr->ch[target[tmpInd]-'a'];
            if (curr->cost != INT_MAX) {
                currCost = min(currCost, curr->cost + dfs(tmpInd+1, target, dp, root));
            }
            tmpInd++;
        }

        return dp[ind] = currCost;
    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        this->N = target.size();
        vector<int> dp(N, INT_MAX/2);
        this->root = new TrieNode();

        for (int i=0; i<words.size(); i++) {
            root->insert(root, words[i], costs[i]);
        }

        if (root->ch[target[0]-'a'] == nullptr) return -1;

        dfs(0, target, dp, root);

        return (dp[0]>=INT_MAX/2?-1:dp[0]);
    }
};