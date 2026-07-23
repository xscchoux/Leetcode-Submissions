class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int N = nums.size();
        if (N <= 2) return N;

        int msb = log2(N);  // we can get all permutations once we have the msb...based on observation

        return pow(2, msb+1);
    }
};