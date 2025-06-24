// binary search
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> arr;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == key) arr.push_back(i);
        }
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            int largerIdx = upper_bound(begin(arr), end(arr), i) - begin(arr);
            if (largerIdx < arr.size() && arr[largerIdx]-i <= k ) {
                res.push_back(i);
                continue;
            }
            if (largerIdx-1 >= 0 && i-arr[largerIdx-1] <= k) {
                res.push_back(i);
            }
        }
        return res;
    }
};


// clever two-pointer solution
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int start = 0, N = nums.size();
        vector<int> res;

        for (int i=0; i<N; i++) {
            if (nums[i] == key) {
                int left = max(0, i-k), right = min(N-1, i+k);
                while (start <= right) {
                    if (start >= left) {
                        res.push_back(start);
                    } 
                    start++;
                }
            }
        }

        return res;
    }
};