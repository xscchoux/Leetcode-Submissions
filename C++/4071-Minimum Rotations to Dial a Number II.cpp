class Solution {
public:
    int minRotations(int n, string s) {
        int N = s.size();
        int res = INT_MAX;

        vector<int> suffixCost(N, 0);
        int costSum = 0;
        for (int i=N-2; i>=0; i--) {
            costSum += min(abs(s[i]-s[i+1]), 10-abs(s[i]-s[i+1]));
            suffixCost[i] = costSum;
        }

        res = suffixCost[0] +  min(abs(s[N-1]-'0'), 10-abs(s[N-1]-'0'));

        int prefixSum = 0;
        for (int i=0; i<N-1; i++) {
            prefixSum += i==0? min(abs(s[i]-'0'), 10-abs(s[i]-'0')) : min(abs(s[i]-s[i-1]), 10-abs(s[i]-s[i-1]));
            res = min(res, prefixSum + min(abs(s[N-1]-s[i]), 10-abs(s[N-1]-s[i])) + suffixCost[i+1]);
        }

        return res;
    }
};