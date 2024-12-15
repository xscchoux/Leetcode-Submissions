// two monotonic stacks
class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int N = nums.size();
        vector<int> left(N, -1), right(N, N); // index of next larger num on the left, index of next larger num on the right 

        stack<int> stk;
        for (int i=0; i<N; i++) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        stack<int> stk2;
        for (int i=N-1; i>=0; i--) {
            while (!stk2.empty() && nums[i] > nums[stk2.top()]) {
                left[stk2.top()] = i;
                stk2.pop();
            }
            stk2.push(i);
        }

        vector<int> res;
        for (int i=0; i<N; i++) {
            res.push_back(right[i]-left[i]-1);
        }

        return res;
    }
};


// clever one-pass solution, no need to check both left and right
class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N);
        nums.push_back(1e9);

        stack<int> stk;
        for (int i=0; i<N+1; i++) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                int curr = stk.top();
                stk.pop();
                int left = stk.empty()?-1:stk.top();
                res[curr] = i-left-1;
            }
            stk.push(i);
        }

        return res;
    }
};