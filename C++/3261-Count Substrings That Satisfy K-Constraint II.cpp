using LL = long long;
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int N = s.size();
        vector<int> leftBound(N), cnt(2, 0); // leftBound[i] is the leftmost index for each substring ends with s[i]
        int left = N-1;
        for (int i=N-1; i>=0; i--) {
            if (i < N-1) cnt[s[i+1]-'0']--;
            while (left >= 0 && ( cnt[s[left]-'0'] + 1 <= k || cnt[(s[left]-'0')^1] <= k )) {
                cnt[s[left]-'0']++;
                left--;
            }
            if (left < 0) leftBound[i] = 0;
            else leftBound[i] = left+1;
        }

        vector<LL> preSum(N+1, 0);
        for (int i=0; i<N; i++) {
            preSum[i+1] = preSum[i] + (i-leftBound[i]+1);
        }

        vector<LL> res;
        for (auto q:queries) {
            int start = q[0], end = q[1];
            int lastIdx = upper_bound(leftBound.begin(), leftBound.end(), start) - leftBound.begin() - 1;
            lastIdx = min(lastIdx, end);
            LL num = (lastIdx-start+1);  // number of indexes within [start, end] which have leftBound[index] <= start
            LL cnt = num*(num+1)/2;
            if (lastIdx < end) {
                cnt += preSum[end+1] - preSum[lastIdx+1];
            }
            res.push_back(cnt);
        }
        return res;
    }
};