class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int N = tasks.size();
        vector<long long> preSum(N, 0);
        vector<int> res;

        preSum[0] = tasks[0];
        for (int i=1; i<N; i++) {
            preSum[i] = preSum[i-1] + tasks[i]; 
        }

        long long shiftSum = 0;

        for (int i=0; i<shifts.size(); i++) {
            shiftSum += shifts[i];
            int idx = upper_bound(begin(preSum), end(preSum), shiftSum) - begin(preSum);
            if (idx == N) {
                res.push_back(0);
                shiftSum = 0;
            } else {
                res.push_back(N-idx);
            }
        }

        return res;
    }
};