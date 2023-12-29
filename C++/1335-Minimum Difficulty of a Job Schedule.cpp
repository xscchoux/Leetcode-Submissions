class Solution {
public:
    int N;
    int cal(vector<int>& jobDifficulty, vector<vector<int>>& memo, int idx, int remain){
        if (idx == N) return 0;
        if (remain <= 0) return INT_MAX/2;
        if (memo[idx][remain] != -1) return memo[idx][remain];
        // put jobs
        int currMax = 0;
        int res = INT_MAX/2;
        for (int i=idx; i<N; i++){
            if (N-i < remain) break;
            currMax = max(currMax, jobDifficulty[i]);
            res = min(res, currMax + cal(jobDifficulty, memo, i+1, remain-1));
        }
        return memo[idx][remain] = res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this->N = jobDifficulty.size();
        vector<vector<int>> memo(N+1, vector<int>(d+1, -1));
        if (N < d)  return -1;
        
        return cal(jobDifficulty, memo, 0, d);
    }
};