class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int N = nums.size(), cnt = 0;
        long long res = 0;
        unordered_map<int, int> hmap;
        hmap[0]++;

        for (int i=0; i<N; i++) {
            cnt += nums[i]%modulo == k;
            res += hmap[(cnt-k+modulo)%modulo];
            hmap[cnt%modulo]++;
        }

        return res;
    }
};