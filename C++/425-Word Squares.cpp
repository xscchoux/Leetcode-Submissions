// O(N × 26^L), where L is the word length (1 ≤ L ≤ 4)
// 26^L represents all possible lowercase alphabet combinations of length L
class Solution {
public:
    int N;
    vector<vector<string>> res;
    void dfs(int cnt, vector<string>& curr, vector<string>& words, unordered_map<string, vector<int>>& prefixMap) {
        if (cnt == N) {
            res.push_back(curr);
            return;
        }

        string prefix = "";
        for (int i=0; i<curr.size(); i++) {
            prefix.push_back(curr[i][cnt]);
        }

        for (int wordIdx:prefixMap[prefix]) {
            curr.push_back(words[wordIdx]);
            dfs(cnt+1, curr, words, prefixMap);
            curr.pop_back();
        }

    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        unordered_map<string, vector<int>> prefixMap;
        this->N = words[0].size();
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<N; j++) {
                string w = words[i].substr(0, j);
                prefixMap[w].push_back(i);
            }
        }

        for (int i=0; i<words.size(); i++) {
            vector<string> arr = {words[i]};
            dfs(1, arr, words, prefixMap);
        }

        return res;
    }
};