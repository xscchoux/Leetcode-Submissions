class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int N = nums.size(), left = 0, pairs = 0;
        long long res = 0;
        unordered_map<int, int> cnt;

        for (int i=0; i<N; i++) {
            cnt[nums[i]]++;
            pairs += (cnt[nums[i]]*(cnt[nums[i]]-1)/2 - (cnt[nums[i]]-1)*(cnt[nums[i]]-2)/2);
            while (pairs >= k) {
                cnt[nums[left]]--;
                pairs -= (cnt[nums[left]]*(cnt[nums[left]]+1)/2 - cnt[nums[left]]*(cnt[nums[left]]-1)/2);
                left++;
            }
            res += left;
        }

        return res;
    }
};


// better
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int N = nums.size(), left = 0, pairs = 0;
        long long res = 0;
        unordered_map<int, int> cnt;

        for (int i=0; i<N; i++) {
            pairs += cnt[nums[i]];
            cnt[nums[i]]++;

            while (left <= i && pairs >= k) {
                res += N-i;
                pairs -= cnt[nums[left]]-1;
                cnt[nums[left++]]--;
            }
        }

        return res;
    }
};