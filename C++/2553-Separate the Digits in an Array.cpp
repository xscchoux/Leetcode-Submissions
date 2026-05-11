class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> arr;
        int N = nums.size();

        for (int i = N-1; i>=0; i--) {
            int tmp = nums[i];
            while (tmp > 0) {
                arr.push_back(tmp%10);
                tmp /= 10;
            }
        }
        reverse(begin(arr), end(arr));
        return arr;
    }
};