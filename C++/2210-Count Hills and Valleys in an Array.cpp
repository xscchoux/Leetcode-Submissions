class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        for (int i=0; i<nums.size(); i++) {
            if (i == 0) {
                arr.push_back(nums[i]);
            } else if (nums[i-1] != nums[i]) {
                arr.push_back(nums[i]);
            }
        }

        int res = 0;
        if (arr.size() < 3) {
            return 0;
        }


        for (int i=1; i<arr.size()-1; i++) {
            if ( (arr[i-1] < arr[i] && arr[i+1] < arr[i]) || (arr[i-1] > arr[i] && arr[i+1] > arr[i]) ) {
                res++;
            }
        }

        return res;
    }
};