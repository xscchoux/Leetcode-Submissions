class Solution {
public:
    int countEffective(vector<int>& nums) {
        const int N = nums.size(), kMod = 1e9+7;
        vector<int> pow2(N+1, 0);
        pow2[0] = 1;
        for (int i=1; i<=N; i++) {
            pow2[i] = (pow2[i-1]*2)%kMod;
        }
        
        int or_all = 0;
        for (int i=0; i<N; i++) {
            or_all |= nums[i];
        }

        int B = log2(or_all) + 1;
        vector<int> dp(1<<B, 0);  // dp[mask]: the number of integers in nums that are submask of mask 
        

        // SOS DP template
        for (int num:nums) {
            dp[num]++;
        }

        for(int i = 0; i < B; ++i) {
            for(int mask = 0; mask < (1<<B); ++mask){
                if(mask & (1<<i)) {
                    dp[mask] += dp[mask^(1<<i)];
                }
            }
        }

        int tot = 0, curr_or = or_all;  // tot : the number of subsequences that ORsub = or_all
                                        // tot also corresponds to the number of ineffective subsequence

        // Use Inclusion-Exclusion Principle to calculate "tot"
        while (true) {
            int sign = __builtin_popcount(curr_or^or_all) %2 ?-1:1;
            tot = ((tot + sign*pow2[dp[curr_or]])%kMod + kMod)%kMod;
            if (curr_or == 0) break;
            curr_or = (curr_or-1) & or_all;
        }

        // all subsequences - ineffective subsequences
        return (pow2[N] - tot + kMod)%kMod;
    }
};