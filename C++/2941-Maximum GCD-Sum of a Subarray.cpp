using LL = long long;
class Solution {
public:
    long long maxGcdSum(vector<int>& nums, int k) {
        int N = nums.size();
        LL res = 0;
        vector<LL> preSum = {0};
        vector<pair<int, int>> gcdArr; 
        // keep GCD values {starting index, gcd value including indexes from the starting index to the last index}
        for (int i=0; i<N; i++) {
            preSum.push_back(preSum.back()+nums[i]);
            vector<pair<int, int>> new_gcd; // new GCD values after appending a new number
            // Note that the length of gcdArr is log(M), where M is max value in nums. This is because GCD can only decrease by at least a half, till it reaches 1
            for (auto &[ind, gcdVal]:gcdArr) {
                int gcdNew = gcd(gcdVal, nums[i]);
                if (new_gcd.empty() || (new_gcd.back().second != gcdNew) ) {
                    new_gcd.push_back({ind, gcdNew});
                }
            }
            if (new_gcd.empty() || (new_gcd.back().second != nums[i]) ) {
                new_gcd.push_back({i, nums[i]});
            }

            gcdArr = new_gcd;

            for (auto &[ind, gcdVal]:gcdArr) {
                if (i-ind+1 >= k) {
                    res = max(res, gcdVal*(preSum[i+1]-preSum[ind]));
                }
            }
        }
        return res;
    }
};