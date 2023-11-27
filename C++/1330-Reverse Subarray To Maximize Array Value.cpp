class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int mx = INT_MIN, mn = INT_MAX;
        int change = 0;
        int N = nums.size();
        int tot = 0;
        for (int i=0; i<N-1; i++){
            int a = nums[i], b = nums[i+1];
            tot += abs(a-b);
            mx = max(min(a, b), mx);
            mn = min(max(a, b), mn);
        }
        change = max(change, 2*(mx-mn));
        
        for (int i=0; i<N-1; i++){
            int a = nums[i], b = nums[i+1];
            int tmp1 = -abs(a-b) + abs(nums[0]-b);
            int tmp2 = -abs(a-b) + abs(a-nums[N-1]);
            change = max(change, max(tmp1, tmp2));
        }       

        return tot + change;

    }
};