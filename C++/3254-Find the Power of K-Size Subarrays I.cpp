class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int N = nums.size();
        for (int i=0; i<N-k+1; i++) {
            int prev = -1;
            bool flag = true;
            for (int curr=i; curr<i+k; curr++) {
                if (curr == i) {
                    prev = nums[curr];
                } else {
                    if (nums[curr] != prev+1) {
                        res.push_back(-1);
                        flag = false;
                        break;
                    } else {
                        prev = nums[curr];
                    }
                }
            }
            if (flag) {
                res.push_back(nums[i+k-1]);
            }
        }
        return res;
    }
};


// O(n) solution using deque
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() < i-k+1 ) {
                dq.pop_front();
            }
            if (i > 0 && nums[i-1] != nums[i]-1 ) {
                dq.clear();
            }
            dq.push_back(i);

            if (i >= k-1) {
                if (dq.size() == k) {
                    res.push_back(nums[i]);
                } else {
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};