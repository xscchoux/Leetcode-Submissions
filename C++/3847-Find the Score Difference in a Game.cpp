class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int players[2] = {};
        int active = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i]%2) {
                active = 1 - active;
            }
            if (i%6 == 5) {
                active = 1 - active;
            }
            players[active] += nums[i];
        }

        return players[0] - players[1];
    }
};