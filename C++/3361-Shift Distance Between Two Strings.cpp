// prefix sum, fast but not easy to get first AC
using LL = long long;
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        nextCost.insert(nextCost.end(), nextCost.begin(), nextCost.end());
        previousCost.insert(previousCost.end(), previousCost.begin(), previousCost.end());        

        vector<LL> preSumNext(53, 0), preSumPre(53, 0);
        for (int i=0; i<52; i++) {
            preSumNext[i+1] = preSumNext[i] + nextCost[i];
            preSumPre[i+1] = preSumPre[i] + previousCost[i];            
        }
        int N = s.size();
        LL tot = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == t[i]) continue;
            int dist = t[i]-s[i];
            if (dist > 0) {
                tot += min(preSumNext[s[i]-'a'+dist]-preSumNext[s[i]-'a'], preSumPre[(s[i]-'a'+1+26)] - preSumPre[(s[i]-'a'+1+26)-(26-dist)]); // forward and backward
            } else {
                tot += min(preSumNext[s[i]-'a'+(26+dist)]-preSumNext[s[i]-'a'], preSumPre[(s[i]-'a'+1+26)] - preSumPre[(s[i]-'a'+1+26)+dist]);
            }
        }

        return tot;
    }
};

// Floyd-Warshall
using LL = long long;
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        vector<vector<LL>> dp(26, vector<LL>(26, LLONG_MAX/3));
        for (int i=0; i<26; i++) {
            dp[i][(i+1)%26] = nextCost[i];
        }

        for (int i=0; i<26; i++) {
            dp[i][(i-1+26)%26] = previousCost[i];
        }

        for (int k=0; k<26; k++) {
            for (int i=0; i<26; i++) {
                for (int j=0; j<26; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }


        LL tot = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == t[i]) continue;
            tot += dp[s[i]-'a'][t[i]-'a'];
        }

        return tot;
    }
};