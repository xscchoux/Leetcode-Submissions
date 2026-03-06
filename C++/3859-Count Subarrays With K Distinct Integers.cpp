// sliding window
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int N = nums.size(), left = 0, distinct = 0, valid = 0;
        long long leftExcess = 0, res = 0;
        unordered_map<int, int> cnt;

        for (int i=0; i<N; i++) {
            if (!cnt.contains(nums[i])) {
                distinct++;
            }
            cnt[nums[i]]++;
            if (cnt[nums[i]] == m) {
                valid++;
            }

            // shrink the window when the count of distinct integers > k
            if (distinct > k) {
                leftExcess = 0;
                while (left < i && distinct > k) {
                    if (cnt[nums[left]] == m) {
                        valid--;
                    }
                    cnt[nums[left]]--;
                    if (cnt[nums[left]] == 0) {
                        distinct--;
                        cnt.erase(nums[left]);
                    }
                    left++;
                }
            }

            // found the subarray with k distinct integers and each of them appears at least m times, so calculate leftExcess
            if (distinct == k && valid == distinct) {
                while (left < i && cnt[nums[left]] > m) {
                    cnt[nums[left]]--;
                    leftExcess++;
                    left++;
                }
                res += leftExcess+1;
            }
        }

        return res;
    }
};



// Clever and hard solution using two maps
// https://leetcode.com/problems/count-subarrays-with-k-distinct-integers/solutions/7616252/hard-easy-dual-sliding-window-strategy-e-cym4/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int N = nums.size();
        int distinct_left = 0, valid_left = 0, valid_cnt = 0;
        long long res = 0;
        unordered_map<int, int> distinct_map, valid_map;

        for (int i=0; i<N; i++) {

            // [distinct_left ... i] : longest subarray with k distinct integer ending with i
            distinct_map[nums[i]]++;
            while (distinct_map.size() > k) {
                distinct_map[nums[distinct_left]]--;
                if (distinct_map[nums[distinct_left]] == 0) {
                    distinct_map.erase(nums[distinct_left]);
                }
                distinct_left++;
            }

            // [valid_left ... i] : we hope that [valid_left-1 ... i] have k numbers (valid_cnt) that meet the m threshold
            // Note that [valid_left ... i] may have more than k distinct numbers. In this case, valid_left > distinct_left
            valid_map[nums[i]]++;
            if (valid_map[nums[i]] == m) valid_cnt++;

            while (valid_cnt == k) {
                if (valid_map[nums[valid_left]] == m) {
                    valid_cnt--;
                }
                valid_map[nums[valid_left]]--;
                valid_left++;
            }

            if (distinct_left < valid_left) res += valid_left - distinct_left;

        }

        return res;
    }
};