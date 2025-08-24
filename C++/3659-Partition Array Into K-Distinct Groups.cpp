class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int N = nums.size();
        if (N%k != 0) return false;

        int Nbucket = N/k;
        unordered_map<int, int> cnt;

        for (int i=0; i<N; i++) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] > Nbucket) return false;
        }

        return true;
    }
};