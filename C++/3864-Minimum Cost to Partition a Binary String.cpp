class Solution {
public:
    int flatCost, encCost;
    long long dfs(int start, int end, vector<int>& preSum) {
        int one_cnt = preSum[end+1] - preSum[start], length = end-start+1;
        if (one_cnt == 0) {
            return flatCost;
        }
        if (length%2) {
            return (long long)length*one_cnt*encCost;
        }

        long long res = (long long)length*one_cnt*encCost;

        long long left = dfs(start, start + length/2 - 1, preSum);
        long long right = dfs(start + length/2, end, preSum);

        return min(res, left+right);

    }
    long long minCost(string s, int encCost, int flatCost) {
        this->encCost = encCost;
        this->flatCost = flatCost;

        int N = s.size();

        vector<int> preSum(N+1, 0);
        for (int i=0; i<N; i++) {
            preSum[i+1] = preSum[i] + (s[i]=='1');
        }

        return dfs(0, N-1, preSum);
    }
};