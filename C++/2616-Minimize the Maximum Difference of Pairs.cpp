class Solution {
public:
    bool isOK(int limit, int p, vector<int>& nums) {
        int cnt = 0;
        int N = nums.size();
        for (int i=0; i<N-1; i++) {
            if (nums[i+1] - nums[i] <= limit) {
                cnt++;
                i++;
            }
        }

        return cnt>=p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        if (nums.size() <= 1) return 0;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int left = 0, right = nums[N-1]-nums[0];
        
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(mid, p, nums)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(left, p, nums)) return left;
        
        return right;
    }
};