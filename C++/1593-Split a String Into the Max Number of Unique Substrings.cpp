// backtracking, O(n*2^n)
class Solution {
public:
    int N;
    int res = 0;
    void dfs(int ind, string& s, unordered_set<string>& used, int count) {
        if (ind == N) {
            res = max(res, count);
            return;
        }

        if (count+N-ind <= res) return;  // smart pruning

        for (int i=ind; i<N; i++) {
            string newS = s.substr(ind, i-ind+1);
            if (!used.contains(newS)) {
                used.insert(newS);
                dfs(i+1, s, used, count+1);
                used.erase(newS);
            }
        }
    }
    int maxUniqueSplit(string s) {
        N = s.size();
        unordered_set<string> used;
        dfs(0, s, used, 0);
        return res;
    }
};