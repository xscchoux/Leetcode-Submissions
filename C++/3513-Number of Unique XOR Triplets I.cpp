class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int N = nums.size();
        if (N <= 2) return N;
        
        int OR = 0;
        for (int num:nums) {
            OR |= num;
        }

        int msb = log2(OR);  // we can get all permutations once we have the msb...based on observation

        return pow(2, msb+1);
    }
};