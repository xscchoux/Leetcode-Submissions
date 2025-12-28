// First AC
class Solution {
public:
    long long dp[16][16][2][270];   // dp[remain][index][limit][evenMinusOdd] , parity: odd:1, even:0
    long long dfs(int remain, int index, int limit, int evenMinusOdd, string& s) {
        if (remain == 0) {
            if (evenMinusOdd == 135) {
                return 1;
            }
            return 0;
        }

        if (dp[remain][index][limit][evenMinusOdd] != -1) return dp[remain][index][limit][evenMinusOdd];
        
        long long res = 0;
        if (limit == 0) {
            for (int i=(index==0?1:0); i<=9; i++) {
                res = res + dfs(remain-1, index+1, limit, evenMinusOdd + (index%2==0?-1*i:i), s);
            }
        } else {
            for (int i=(index==0?1:0); i<=s[index]-'0'; i++) {
                res = res + dfs(remain-1, index+1, (i==s[index]-'0')?1:0, evenMinusOdd + (index%2==0?-1*i:i), s);
            }
        }

        return dp[remain][index][limit][evenMinusOdd] = res;
    }
    long long cal(int remain, string &s) {
        long long tot = 0;
        for (int length=1; length<=remain; length++) {
            tot += dfs(length, 0, length==remain?1:0, 135, s);
        }
        return tot;
    }
    long long countBalanced(long long low, long long high) {
        memset(dp, -1, sizeof(dp));
        int N1 = log10(high)+1;
        string highNum = to_string(high);
        long long res1 = cal(N1, highNum);

        long long res2 = 0;
        if (low-1 > 0) {
            memset(dp, -1, sizeof(dp));
            int N2 = log10(low-1)+1;
            string lowNum = to_string(low-1);
            res2 = cal(N2, lowNum);   
        }


        return res1-res2;
    }
};



// Better
class Solution {
public:
    long long dp[16][2][270];   // dp[index][limit][evenMinusOdd] , parity: odd:1, even:0
    long long dfs(int index, int limit, int evenMinusOdd, string& s) {
        if (index == s.size()) {
            if (evenMinusOdd == 135) {
                return 1;
            }
            return 0;
        }

        if (dp[index][limit][evenMinusOdd] != -1) return dp[index][limit][evenMinusOdd];
        
        long long res = 0;
        if (limit == 0) {
            for (int i=0; i<=9; i++) {
                res = res + dfs(index+1, limit, evenMinusOdd + (index%2==0?-1*i:i), s);
            }
        } else {
            for (int i=0; i<=s[index]-'0'; i++) {
                res = res + dfs(index+1, (i==s[index]-'0')?1:0, evenMinusOdd + (index%2==0?-1*i:i), s);
            }
        }

        return dp[index][limit][evenMinusOdd] = res;
    }
    long long countBalanced(long long low, long long high) {
        memset(dp, -1, sizeof(dp));
        string highNum = to_string(high);
        long long res1 = dfs(0, 1, 135, highNum);

        memset(dp, -1, sizeof(dp));
        string lowNum = to_string(low-1);
        long long res2 = dfs(0, 1, 135, lowNum);

        return res1-res2;
    }
};