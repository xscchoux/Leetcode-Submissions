class Solution {
public:
    bool dfs(string s1, string s2, unordered_map<string, bool>& memo){
        string sorted_s1 = s1;
        string sorted_s2 = s2;
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());
        if (sorted_s1 != sorted_s2) return false;
        
        if (s1.size() == 1) return true;
        
        string key = s1 + " " + s2;
        
        if (memo.count(key)) return memo[key];
        
        int N = s1.size();
        
        for (int i=1; i<N; i++){
            if ( dfs(s1.substr(0, i), s2.substr(0, i), memo) && dfs(s1.substr(i), s2.substr(i), memo) ){
                memo[key] = true;
                return true;
            }
        }
        
        for (int i=1; i<N; i++){
            if ( dfs(s1.substr(N-i), s2.substr(0, i), memo) && dfs(s1.substr(0, N-i), s2.substr(i), memo) ){
                memo[key] = true;
                return true;
            }
        }
        memo[key] = false;
        return false;
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> memo;
        return dfs(s1, s2, memo);
    }
};