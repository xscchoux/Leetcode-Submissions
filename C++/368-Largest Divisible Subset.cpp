class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<int> dp(N+1, 1);
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]%nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int maxIdx = 0, mx = 0;
        for (int i=0; i<N; i++) {
            if (dp[i] > mx){
                maxIdx = i;
                mx = dp[i];
            }
        }
        
        vector<int> res;
        
        while (maxIdx >= 0){
            res.push_back(nums[maxIdx]);
            if (maxIdx == 0) break;
            int j = maxIdx-1;
            while (j >= 0) {
                if (nums[maxIdx]%nums[j] == 0 && dp[j] == dp[maxIdx] - 1) {
                    break;
                } else {
                    j--;
                }
            }
            maxIdx = j;
        }
        
        return res;
    }
};




// Second visit, beat 99%
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int N = nums.size(), maxLen = 1, maxNum = nums[0];
        vector<int> dp(N, 1);


        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]%nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j]+1);
                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        maxNum = nums[i];
                    }
                }
            }
        }

        vector<int> res;
        for (int i=N-1; i>=0; i--) {
            if (dp[i] == maxLen && maxNum%nums[i] == 0) {
                res.push_back(nums[i]);
                maxNum = nums[i];
                maxLen--;
            }
        }

        reverse(begin(res), end(res));

        return res;
    }
};