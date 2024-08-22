// O(N*2^N)
class Solution {
public:
    vector<string> res;
    int N;
    void dfs(int ind, string& word, string curr) {
        if (ind == N) {
            res.push_back(curr);
            return;
        }
        // starts with a char;
        dfs(ind+1, word, curr + word[ind]);

        // starts with a digit
        for (int j=ind; j<N; j++) {
            string num = to_string(j-ind+1);
            if (j+1 < N) {
                num += word[j+1];
                dfs(j+2, word, curr + num);
            } else {
                dfs(j+1, word, curr + num);
            }
        }
    }
    vector<string> generateAbbreviations(string word) {
        this->N = word.size();
        dfs(0, word, "");
        return res;
    }
};