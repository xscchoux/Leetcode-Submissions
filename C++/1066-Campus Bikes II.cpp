class Solution {
public:
    int N, M;
    int dfs(int idx, int bitmask, vector<vector<int>>& workers, vector<vector<int>>& bikes, vector<int>& memo) {
        if (idx == N) return 0;
        if (memo[bitmask] != -1) return memo[bitmask];
        int res = INT_MAX/2;
        for (int i=0; i<M; i++){
            if ( ((bitmask>>i) & 1) != 0){
                res = min(res, abs(workers[idx][0]-bikes[i][0])+abs(workers[idx][1]-bikes[i][1]) + dfs(idx+1, bitmask^(1<<i), workers, bikes, memo) );
            }
        }
        return memo[bitmask] = res;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        this->N = workers.size();
        this->M = bikes.size();
        vector<int> memo(1<<M, -1);
        int bitmask = (1<<M) - 1;
        return dfs(0, bitmask, workers, bikes, memo);
        
    }
};