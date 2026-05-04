class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<int> fromLeft(N, 0), fromRight(N, 0);

        // go right (If both adjacent indices exist and give the same difference, choose the smaller index)
        for (int i=0; i<N-1; i++) {
            if (i == 0 || abs(nums[i] - nums[i-1]) > abs(nums[i+1] - nums[i]) ) {
                fromLeft[i+1] = fromLeft[i] + 1;
            } else {
                fromLeft[i+1] = fromLeft[i] + abs(nums[i+1] - nums[i]);
            }
        }

        // go left
        for (int i=N-1; i>0; i--) {
            if (i == N-1 || abs(nums[i] - nums[i-1]) <= abs(nums[i+1] - nums[i]) ) {
                fromRight[i-1] = fromRight[i] + 1;
            } else {
                fromRight[i-1] = fromRight[i] + abs(nums[i]-nums[i-1]);
            }
        }

        vector<int> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            if (v >= u) {
                res.push_back(fromLeft[v] - fromLeft[u]);
            } else {
                res.push_back(fromRight[v] - fromRight[u]);
            }
        }
        
        return res;
    }
};