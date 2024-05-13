class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int N = energy.size();
        vector<int> dp(N, 0);

        for (int i=0; i<N; i++) {
            dp[i] = energy[i] + max(0, (i-k>=0?dp[i-k]:0));
        }
        
        return *max_element(dp.begin()+N-k, dp.end());
    }
};