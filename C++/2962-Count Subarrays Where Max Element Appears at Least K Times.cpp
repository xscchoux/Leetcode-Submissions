class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> arr;
        long res = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == mx){
                arr.push_back(i);
            }
        }

        int count = 0;
        for (int i=0; i<arr.size(); i++){
            count++;
            if (count == k){
                long right = arr.size() - 1, left = 0;
                if (i != arr.size()-1){
                    right = arr[i+1] - arr[i];
                } else {
                    right = nums.size() - arr[i];
                }
                left = arr[i-k+1]+1;
                res += left*right;
                count--;
            }
        }
        return res;
        
    }
};


// Second visit, much simpler
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int left = 0, maxCnt = 0, mx = *max_element(begin(nums), end(nums));

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == mx) maxCnt++;
            while ((maxCnt == k && nums[left] != mx) || maxCnt > k) {
                if (nums[left++] == mx) maxCnt--;
            }
            if (maxCnt == k) {
                res += left+1;
            }
        }

        return res;
    }
};