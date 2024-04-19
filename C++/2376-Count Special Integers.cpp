class Solution {
    int N;
public:
    int permutation(int m, int n) {
        if (n == 0) return 1;
        return m*permutation(m-1, n-1);
    }
    
    int dfs(int ind, string& s, vector<bool>& used) {
        if (ind == N) return 1;
        int tot = 0;
        
        for (int num=0; num<=9; num++) {
            if (ind == 0 && num == 0) continue;
            if (num > s[ind] - '0') break;
            if (used[num]) continue;
            
            if (num == s[ind] - '0') {
                used[num] = true;
                tot += dfs(ind+1, s, used);
                used[num] = false;  // this line is not necessary
            }
            else {
                tot += permutation(10-ind-1, N-ind-1);
            }
        }
        
        return tot;
    }
    
    
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        this->N = s.size();
        int res = 0;
        
        for (int i=1; i<N; i++) {
            res += 9*permutation(9, N-i-1);
        }

        vector<bool> used(10, false);
        
        res += dfs(0, s, used);
        
        return res;
    }
};