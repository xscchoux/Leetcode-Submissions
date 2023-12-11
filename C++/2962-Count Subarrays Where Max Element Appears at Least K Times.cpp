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