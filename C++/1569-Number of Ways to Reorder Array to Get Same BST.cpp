using LL = long long;
constexpr int kMod = 1e9+7;
constexpr int MAX_N = 1000;

vector<vector<LL>> nCr(MAX_N+1, vector<LL>(MAX_N+1, 0));

int fillVector = []() {
    // fill nCr
    nCr[0][0] = 1;
    for (int n=1; n<=MAX_N; n++) {
        nCr[n][0] = 1;
        for (int r=1; r<=min(n, r); r++) {
            nCr[n][r] = (nCr[n-1][r] + nCr[n-1][r-1])%kMod;
        }
    }
    return 0;
}();


class Solution {
public:
    int cal(vector<int>& nums) {
        int N = nums.size();
        if (N <= 2) {
            return 1;
        }

        vector<int> leftNums, rightNums;
        for (int i=1; i<N; i++) {
            if (nums[i] < nums[0]) {
                leftNums.push_back(nums[i]);
            } else {
                rightNums.push_back(nums[i]);
            }
        }

        int Nl = leftNums.size(), Nr = rightNums.size();

        return ((nCr[Nl+Nr][Nl]*cal(leftNums))%kMod)*cal(rightNums)%kMod;
    }

    int numOfWays(vector<int>& nums) {
        return cal(nums)-1;
    }
};