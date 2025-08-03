// O(nlogn), prefix sum + binary search
// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/editorial
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int N = fruits.size();
        vector<int> preSum(N+1, 0), idx;

        for (int i=0; i<N; i++) {
            preSum[i+1] = preSum[i] + fruits[i][1];
            idx.push_back(fruits[i][0]);
        }

        int res = 0;
        for (int x=0; 2*x <= k; x++) {
            // move left then move right
            int left = startPos-x, right = left+k-x;
            int leftIdx = lower_bound(begin(idx), end(idx), left) - begin(idx);
            int rightIdx = upper_bound(begin(idx), end(idx), right) - begin(idx);
            res = max(res, preSum[rightIdx] - preSum[leftIdx]);

            // move right then move left
            right = startPos+x, left = right-(k-x);
            leftIdx = lower_bound(begin(idx), end(idx), left) - begin(idx);
            rightIdx = upper_bound(begin(idx), end(idx), right) - begin(idx);
            res = max(res, preSum[rightIdx] - preSum[leftIdx]);            

        }

        return res;
    }
};



// O(n), sliding window
// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/editorial
class Solution {
public:
    int startPos;
    int stepCost(int leftIdx, int rightIdx, vector<vector<int>>& fruits) {
        // the window is at the left side
        if (fruits[rightIdx][0] <= startPos) {
            return startPos - fruits[leftIdx][0];
        } else if (fruits[leftIdx][0] >= startPos) {  // the window is at the right side
            return fruits[rightIdx][0] - startPos;
        } else { // this startPos is inside the window
            return min(fruits[rightIdx][0] - startPos, startPos - fruits[leftIdx][0]) + (fruits[rightIdx][0] - fruits[leftIdx][0]);
        }
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int N = fruits.size(), left = 0, res = 0, curr = 0;
        this->startPos = startPos;
        for (int i=0; i<N; i++) {  // i: right
            curr += fruits[i][1];
            while (left <= i && stepCost(left, i, fruits) > k) {
                curr -= fruits[left][1];
                left++;
            }
            res = max(res, curr);
        }

        return res;
    }
};