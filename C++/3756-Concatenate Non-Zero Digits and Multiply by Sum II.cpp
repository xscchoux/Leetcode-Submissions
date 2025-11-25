// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/solutions/7368397/fully-explained-code-by-c_prateek-kfsj/
class Solution {
public:
    long long kMod = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int N = s.size();
        vector<long long> preSum(N+1, 0), preNumber(N+1, 0);  // prefix sum, concatenated number
        vector<int> mapping(N+1, 0), res;  // map to index in preSum and preNumber
        vector<long long> pow10(N+1, 0);

        pow10[0] = 1;
        for (int i=1; i<=N; i++) {
            pow10[i] = (pow10[i-1]*10)%kMod;
        }

        int idx = 0; // index for preSum and preNumber
        for (int i=0; i<s.size(); i++) {
            if (s[i] != '0') {
                idx++;
                preSum[idx] = (preSum[idx-1] + (s[i]-'0'))%kMod;
                preNumber[idx] = (preNumber[idx-1]*10 + (s[i]-'0'))%kMod;
            }
            mapping[i] = idx;
        }

        for (auto &q:queries) {
            int u = q[0], v = q[1];
            int mappedU = u==0?0:mapping[u-1], mappedV = mapping[v];
            int sum = (preSum[mappedV] - preSum[mappedU] + kMod)%kMod;
            int concatenated = (preNumber[mappedV] - (preNumber[mappedU]*pow10[mappedV-mappedU])%kMod + kMod)%kMod;
            long long val = (long long)sum*concatenated%kMod;
            res.push_back(val);
        }

        return res;
    }
};