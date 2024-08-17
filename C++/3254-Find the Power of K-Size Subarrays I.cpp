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