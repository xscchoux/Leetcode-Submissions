// First AC
using PII = pair<int, int>;
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int N = nums.size();
        set<PII> s;

        vector<int> right(N, N), left(N, -1);
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


        for (int i=0; i<N; i++) {
            if (left[i] != -1 && right[i] != N) {
                PII p = make_pair(left[i], right[i]);
                s.insert(p);
            }
        }

        return s.size();
    }
};


// monotonic decreasing stack
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int res = 0, N = nums.size();
        stack<int> stk;

        for (int i=0; i<N; i++) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                stk.pop();
                if (!stk.empty()) {
                    res++;
                }
            }
            stk.push(i);
        }

        return res;
    }
};