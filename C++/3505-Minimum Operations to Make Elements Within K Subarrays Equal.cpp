// Two multisets + top-down DP
using LL = long long;
class Solution {
public:
    int N, k, x;
    LL memo[100001][20];
    long long minOperations(vector<int>& nums, int x, int k) {
        multiset<LL> upper, lower;
        N = nums.size();
        this->k = k;
        this->x = x;
        vector<LL> cost(N, LLONG_MAX/3);  // the minimum operations needed to make numbers from idx ~ idx+x-1 equal, change all of them to median
        LL lowerSum = 0, upperSum = 0;

        for (int i=0; i<N; i++) {
            // add current number
            if (lower.empty() || nums[i] <= *rbegin(lower) ) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }

            // remove the (i-x)th element
            if (i >= x) {
                if (lower.contains(nums[i-x])) {
                    lower.erase(lower.find(nums[i-x]));
                    lowerSum -= nums[i-x];
                } else {
                    upper.erase(upper.find(nums[i-x]));
                    upperSum -= nums[i-x];
                }
            }

            // balance the two multisets
            while ( (int)lower.size() - 1 > (int)upper.size()) {
                int val = (*rbegin(lower));
                upper.insert(val);
                upperSum += val;
                lower.erase(lower.find(val));
                lowerSum -= val;
            }

            while ((int)upper.size() > (int)lower.size()) {
                int val = *begin(upper);
                lower.insert(val);
                lowerSum += val;
                upper.erase(upper.find(val));
                upperSum -= val;                
            }

            if (i >= x-1) {
                LL median = *rbegin(lower);
                cost[i-x+1] = (median*((int)lower.size()) - lowerSum) + (upperSum - median*(int)(upper.size()));
            }
        }

        memset(memo, -1, sizeof(memo));

        return dp(0, 0, cost);
    }
private:
    LL dp(int idx, int subarrays, vector<LL>& cost) {
        if (idx == N) {
            if (subarrays >= k) {
                return 0;
            }
            return LLONG_MAX/3;
        }

        if (memo[idx][subarrays] != -1) return memo[idx][subarrays];

        // skip
        LL res = dp(idx+1, subarrays, cost);

        // take
        if (idx + x <= N && subarrays+1 <= k) {
            res = min(res, cost[idx] + dp(idx+x, subarrays+1, cost));
        }

        return memo[idx][subarrays] = res;
    }
};


// Bottom-up DP, faster
using LL = long long;
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        multiset<LL> upper, lower;
        int N = nums.size();
        vector<LL> cost(N, LLONG_MAX/2);
        LL lowerSum = 0, upperSum = 0;

        for (int i=0; i<N; i++) {
            // add current number
            if (lower.empty() || nums[i] <= *rbegin(lower) ) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }

            // remove the (i-x)th element
            if (i >= x) {
                if (lower.contains(nums[i-x])) {
                    lower.erase(lower.find(nums[i-x]));
                    lowerSum -= nums[i-x];
                } else {
                    upper.erase(upper.find(nums[i-x]));
                    upperSum -= nums[i-x];
                }
            }

            // balance the two multisets
            while ( (int)lower.size() - 1 > (int)upper.size()) {
                int val = (*rbegin(lower));
                upper.insert(val);
                upperSum += val;
                lower.erase(lower.find(val));
                lowerSum -= val;
            }

            while ((int)upper.size() > (int)lower.size()) {
                int val = *begin(upper);
                lower.insert(val);
                lowerSum += val;
                upper.erase(upper.find(val));
                upperSum -= val;                
            }

            if (i >= x-1) {
                LL median = *rbegin(lower);
                cost[i-x+1] = (median*((int)lower.size()) - lowerSum) + (upperSum - median*(int)(upper.size()));
            }
        }


        vector<vector<LL>> dp(N, vector<LL>(k+1, LLONG_MAX/2));
        for (int i=N-1; i>=0; i--) {
            dp[i][1] = cost[i];
            if (i+1 < N) dp[i][1] = min(dp[i][1], dp[i+1][1]);

            for (int kk=2; kk <= k; kk++) {
                if (i + x < N) {
                    dp[i][kk] = min(dp[i+1][kk], cost[i] + dp[i+x][kk-1]); 
                }
            }
        }

        return dp[0][k];
    }
};

