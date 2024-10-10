// binary search
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int N = nums.size();
        vector<int> arr;
        arr.push_back(nums[0]);

        int res = 0;
        for (int i=1; i<N; i++) {
            int index = lower_bound(begin(arr), end(arr), nums[i], greater<int>()) - arr.begin();
            res = max(res, i-index);
            arr.push_back(min(arr[i-1], nums[i]));
        }

        return res;
    }
};

// use strictly decreasing monotonic stack
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int N = nums.size();
        stack<int> stk;

        for (int i=0; i<N; i++) {
            if (stk.empty() || nums[i] < nums[stk.top()]) {
                stk.push(i);
            }
        }

        int res = 0;
        for (int i=N-1; i>res; i--) {  // it's very clever to use i>res
            while (!stk.empty() && nums[i] >= nums[stk.top()]) {
                res = max(res, i-stk.top());
                stk.pop();
            }
        }

        return res;
    }
};