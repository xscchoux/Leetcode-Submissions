// In C++, global variables are stored in the heap, not the stack. The heap has a much larger size limit than the stack, so it can accommodate larger data structures.
int memo[101][27][101][101];
class Solution {
public:
    int N;
    int dfs(string& s, int idx, int lastChar, int lastCount, int remain) {
        if (idx == N) return 0;
        if (remain >= N - idx) return 0;
        if (memo[idx][lastChar][lastCount][remain] != -1) return memo[idx][lastChar][lastCount][remain];
        // delete
        int deleteCurr = INT_MAX/2, keepCurr = INT_MAX/2;
        if (remain > 0) deleteCurr = dfs(s, idx+1, lastChar, lastCount, remain-1);
        
        // keep, same char
        if ( (s[idx]-'a') == lastChar) keepCurr = dfs(s, idx+1, lastChar, lastCount+1, remain) + ((lastCount==9 || lastCount==99 || lastCount == 1)?1:0);
        // keep, different char
        else keepCurr = dfs(s, idx+1, s[idx]-'a', 1, remain) + 1;
        return memo[idx][lastChar][lastCount][remain] = min(deleteCurr, keepCurr);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        this->N = s.size();
        memset(memo, -1, sizeof(memo));
        return dfs(s, 0, 26, 0, k);
    }
};