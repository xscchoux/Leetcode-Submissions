using PII = pair<int, int>;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int N = nums.size();
        vector<bool> marked(N, false);
        priority_queue<PII, vector<PII>, greater<>> pq;
        for (int i=0; i<N; i++) {
            pq.push({nums[i], i});
        }

        long long res = 0;
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            if (!marked[idx]) {
                marked[idx] = true;
                res += val;
                if (idx > 0) marked[idx-1] = true;
                if (idx < N-1) marked[idx+1] = true;
            }
        }

        return res;
    }
};