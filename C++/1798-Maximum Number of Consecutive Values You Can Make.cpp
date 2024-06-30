class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int prev = 0;
        for (int i=0; i<coins.size(); i++) {
            if (prev+1<coins[i]) return prev+1;
            prev = coins[i] + prev;
        }
        return prev+1;
    }
};