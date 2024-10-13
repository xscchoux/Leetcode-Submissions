// sorting
using PII = pair<int, int>;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<PII> arr;
        for (int i=0; i<k; i++) {
            for (int num:nums[i]) {
                arr.push_back({num, i});
            }
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        vector<int> res = {0, 100000};
        unordered_map<int, int> cnt;
        for (int i=0; i<arr.size(); i++) {
            cnt[arr[i].second]++;
            while (cnt.size() == k) {
                if (res[1]-res[0] > arr[i].first-arr[left].first) res = {arr[left].first, arr[i].first};
                cnt[arr[left].second]--;
                if (cnt[arr[left].second] == 0) {
                    cnt.erase(arr[left].second);
                }
                left++;
            }
        }
        return res;
    }
};


// priority queue
using TII = tuple<int, int, int>;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<TII, vector<TII>, greater<>> pq;
        int k = nums.size();
        int mx = INT_MIN, mn = INT_MAX;
        for (int i=0; i<k; i++) {
            pq.push({nums[i][0], 0, i});
            mx = max(mx, nums[i][0]);
            mn = min(mn, nums[i][0]);
        }

        vector<int> res = {mn, mx};

        while (pq.size() == nums.size()) {
            auto [minVal, colIdx, rowIdx] = pq.top();
            pq.pop();
            if (mx-minVal < res[1]-res[0]) {
                res[0] = minVal;
                res[1] = mx;
            }

            // insert a new element on the same row if possible
            if (colIdx + 1 < nums[rowIdx].size()) {
                pq.push({nums[rowIdx][colIdx+1], colIdx+1, rowIdx});
                mx = max(mx, nums[rowIdx][colIdx+1]);
            }
        }
        return res;
    }
};