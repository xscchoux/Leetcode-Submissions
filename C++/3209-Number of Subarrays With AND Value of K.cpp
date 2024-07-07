// Hashmap
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        long long res = 0;
        unordered_map<int, int> hmap;

        for (int i=0; i<N; i++) {
            if ((nums[i] & k) != k) {
                hmap.clear();
                continue;
            }
            unordered_map<int, int> count;
            count[nums[i]]++;
            for (auto [key, val]:hmap) {
                count[key&nums[i]] += val;
            }
            res += count[k];
            swap(hmap, count);
        }

        return res;
    }
};


// Sliding window
class Solution {
public:
    int getNum(vector<int>& cnt, int left, int i) {
        int num = 0;
        for (int b=0; b<32; b++) {
            if (cnt[b] == i-left+1) {
                num |= (1<<b);
            }
        }
        return num;
    }
    long long counter(vector<int>& nums, int target) {
        long long res = 0;
        int left = 0, N = nums.size();
        vector<int> cnt(32, 0);

        for (int i=0; i<N; i++) {
            for (int b=0; b<32; b++) {
                if ((nums[i]>>b)&1) cnt[b]++;
            }
            while (left <=i && getNum(cnt, left, i) < target) {
                for (int b=0; b<32; b++) {
                    if ((nums[left]>>b)&1) cnt[b]--;
                }
                left++;
            }
            res += (i-left+1);
        }
        return res;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        return counter(nums, k) - counter(nums, k+1);
    }
};