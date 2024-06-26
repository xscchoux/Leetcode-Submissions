class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int res = INT_MAX, N = nums.size(), n = N/2;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> leftVal(n+1), rightVal(n+1);  //[count of items][sum of these items]


        for (int mask=0; mask<(1<<n); mask++) {
            int bitCount = 0, leftSum = 0, rightSum = 0;
            for (int i=0; i<n; i++) {
                if ((mask>>i)&1) {
                    bitCount++;
                    leftSum += nums[i];
                    rightSum += nums[i+n];
                }
            }
            leftVal[bitCount].push_back(leftSum);
            rightVal[bitCount].push_back(rightSum);
        }

        for (int cnt=0; cnt<=n; cnt++) {
            sort(rightVal[cnt].begin(), rightVal[cnt].end());
        }

        for (int cnt=0; cnt<=n; cnt++) {
            int cnt2 = n - cnt;
            auto &v1 = leftVal[cnt], &v2 = rightVal[cnt2];
            for (int val:v1) {
                auto it = lower_bound(v2.begin(), v2.end(), (tot-2*val)/2);
                if (it!=v2.end()) {
                    res = min(res, abs( ((*it) + val)*2-tot ));
                } if (it!=v2.begin()) {
                    it = prev(it);
                    res = min(res, abs( ((*it) + val)*2-tot ));
                }
            }
        }

        return res;
    }
};