class Solution {
public:
    long long maxCaloriesBurnt(vector<int>& heights) {
        sort(begin(heights), end(heights));

        int left = 0, right = heights.size()-1;

        long long curr = heights[right];
        long long res = curr*curr;
        int flag = 1;

        while (left < right) {
            res += (long long)(heights[right]-heights[left])*(heights[right]-heights[left]);
            if (flag) {
                right--;
            } else {
                left++;
            }
            flag = 1-flag;
        }

        return res;
    }
};