// Both solutions are clever

// https://leetcode.com/problems/count-distinct-subarrays-divisible-by-k-in-sorted-array/solutions/7301530/easiest-solution-with-intuition-and-appr-hinr/
// very tricky
class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        int N = nums.size(), curr = 0;
        unordered_map<int, vector<int>> hmap;
        hmap[0].push_back(-1);
        long long res = 0;

        for (int i=0; i<N; i++) {
            curr = (curr + nums[i])%k;
            if (hmap.count(curr)) {
                auto it = lower_bound(hmap[curr].begin(), hmap[curr].end(), nums[i]);
                res += it-hmap[curr].begin();
            }
            hmap[curr].push_back(nums[i]);
        }

        return res;
    }
};


// prefix sum + dedupe
// https://leetcode.com/problems/count-distinct-subarrays-divisible-by-k-in-sorted-array/solutions/7301660/javacpython-prefix-dedupe-by-lee215-w0v6/
class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int curr = 0;
        long long res = 0;

        for (int num:nums) {
            curr = (curr+num)%k;
            res += cnt[curr];
            cnt[curr]++;
        }

        // dedupe
        for (int i=0; i<nums.size();) {
            int j = i;
            while (j<nums.size() && nums[i] == nums[j]) {
                j++;
            }
            j--;
            int length = j-i+1;
            for (int ll=1; ll<length; ll++) {
                if ((long long)ll*nums[i]%k == 0) {
                    res -= length-ll;
                }
            }
            i += length;
        }

        return res;
    }
};