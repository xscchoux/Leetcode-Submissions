// O(n^3*log(n))
class Solution {
public:
    int memo_dp[201][101]; // set 101 because 1 <= k <= s.length / 2
    int memo_v[201][201];
    string s;
    
    int v(int start, int end){
        if (memo_v[start][end] != -1) return memo_v[start][end];
        int length = end-start+1;
        int res = INT_MAX/2;
        // Only O(log(length)) iterations will not hit the continue statement, 
        // so the time complexity for this function is O(length*log(length))
        for (int d=1; d<length; d++){
            if (length%d != 0) continue;
            int currCount = 0;
            int segments = length/d;
            // O(length) time complexity below
            for (int offset=0; offset<d; offset++){
                for (int segmentIdx=0; segmentIdx < segments/2; segmentIdx++){
                    if (s[start+offset+segmentIdx*d] != s[start+offset+(segments-1-segmentIdx)*d]) currCount++;
                }
            }
            res = min(res, currCount);
        }
        memo_v[start][end] = res;
        return res;
    }
    
    int dp(int start, int k){
        if (memo_dp[start][k] != -1) return memo_dp[start][k];
        
        if (k == 1) return v(start, s.size()-1);
        
        int res = INT_MAX/2;
        // Note that there are at least two characters in a semi-palindrome
        for (int mid = start+1; mid <= s.size()-2; mid++){
            res = min(res, v(start, mid) + dp(mid+1, k-1));
        }
        memo_dp[start][k] = res;
        return res;
    }
    
    int minimumChanges(string s, int k) {
        memset(memo_dp, -1, sizeof(memo_dp));
        memset(memo_v, -1, sizeof(memo_v));
        this->s = s;
        return dp(0, k);
    }
};