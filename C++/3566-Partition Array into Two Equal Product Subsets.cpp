using LL = __int128;
class Solution {
public:
    int N;
    bool dfs(int idx, long long curr, long long SQR, vector<bool>& visited, vector<int>& nums) {
        if (idx == N) return false;
        if (curr == SQR) {
            return true;
        }
        // skip
        if (dfs(idx+1, curr, SQR, visited, nums)) {
            return true;
        }
        // pick
        if (curr*nums[idx] <= SQR) {
            visited[idx] = true;
            if (dfs(idx+1, curr*nums[idx], SQR, visited, nums)) {
                return true;
            }
            visited[idx] = false;
        }
        
        return false;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        LL tot = 1LL;
        for (int num:nums) {
            tot *= num;
        }

        // LL SQR = sqrt(tot);  // sqrt does not support __int128
        if (tot%target != 0 || tot/target != target) return false;

        this->N = nums.size();
        vector<bool> visited(N);
        
        bool res = dfs(0, 1, target, visited, nums);
        
        return res;
    }
};