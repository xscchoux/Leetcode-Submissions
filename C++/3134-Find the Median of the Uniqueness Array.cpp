class Solution {
public:
    bool reachMid(int maxDistinct, vector<int>& nums, long numbers) {
        long cnt = 0;
        int left = 0, N = nums.size();
        unordered_map<int, int> hmap;
        for (int i=0; i<N; i++) {
            hmap[nums[i]]++;
            while (hmap.size() > maxDistinct) {
                hmap[nums[left]]--;
                if (hmap[nums[left]] == 0) {
                    hmap.erase(nums[left]);
                }
                left++;
            }
            cnt += i - left + 1;
        }
        return cnt>=numbers;
    }

    int medianOfUniquenessArray(vector<int>& nums) {
        int N = nums.size();
        long tot = (long)N*(N+1)/2;
        long numBeforeMedian = (tot-1)/2;
        int left = 1, right = 1e5;   // maximum distinct numbers in a subarray

        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (reachMid(mid, nums, numBeforeMedian+1)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (reachMid(left, nums, numBeforeMedian+1)) {
            return left;
        }
        return right;
    }
};