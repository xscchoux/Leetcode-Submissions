class Solution {
public:
    int k;
    void dfsLeft(int ind, int remain, int xorVal, vector<int>& leftVal, vector<int>& nums, vector<vector<vector<int>>>& leftDP) {
        if (remain == 0) {
            leftVal[xorVal] = min(leftVal[xorVal], ind-1);
            return;
        }
        if (leftDP[ind][remain][xorVal]) return;
        leftDP[ind][remain][xorVal] = true;
        if (ind + remain + 1 <= nums.size()-k) {
            dfsLeft(ind+1, remain, xorVal, leftVal, nums, leftDP);
        }
        if (ind + remain <= nums.size()-k) {
            dfsLeft(ind+1, remain-1, xorVal|nums[ind], leftVal, nums, leftDP);
        }
    }
    void dfsRight(int ind, int remain, int xorVal, vector<int>& rightVal, vector<int>& nums, vector<vector<vector<int>>>& rightDP) {
        if (remain == 0) {
            rightVal[xorVal] = max(rightVal[xorVal], ind+1);
            return;
        }
        if (rightDP[ind][remain][xorVal]) return;
        rightDP[ind][remain][xorVal] = true;
        if (ind - remain - 1 >= k-1) {
            dfsRight(ind-1, remain, xorVal, rightVal, nums, rightDP);
        }
        if (ind - remain >= k-1) {
            dfsRight(ind-1, remain-1, xorVal|nums[ind], rightVal, nums, rightDP);
        }
    }

    int maxValue(vector<int>& nums, int k) {
        int N = nums.size();
        this->k = k;
        vector<vector<vector<int>>> leftDP(N+1, vector<vector<int>>(k+1, vector<int>(128, false)));
        vector<vector<vector<int>>> rightDP(N+1, vector<vector<int>>(k+1, vector<int>(128, false)));        
        vector<int> leftVal(128, INT_MAX), rightVal(128, 0);
        dfsLeft(0, k, 0, leftVal, nums, leftDP);
        dfsRight(N-1, k, 0, rightVal, nums, rightDP);

        int res = 0;
        for (int left=0; left<128; left++) {
            for (int right = 0; right<128; right++) {
                if (leftVal[left] < rightVal[right]) {
                    res = max(res, left^right);
                }
            }
        }

        return res;
    }
};