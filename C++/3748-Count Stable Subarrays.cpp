// O(N)
// For query [l, r], compute the prefix sum in the range and adjust for the left segment crossing l
class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int running = 0, N = nums.size();
        vector<long long> idx2Length(N, 0), arr;

        for (int i=0; i<N; i++) {
            if (i == 0 || nums[i] >= nums[i-1]) {
                running++;
            } else {
                running = 1;
            }
            arr.push_back(running);
        }

        for (int i=N-1; i>=0; i--) {
            if (i == N-1 || arr[i] >= arr[i+1]) {
                idx2Length[i] = arr[i];
            } else {
                idx2Length[i] = idx2Length[i+1];
            }
        }
        
        vector<long long> preSum(N, 0);
        preSum[0] = arr[0];

        for (int i=1; i<N; i++) {
            preSum[i] = preSum[i-1] + arr[i];
        }

        vector<long long> res;
        for (auto &q:queries) {
            int left = q[0], right = q[1];

            // left and right are within a segment
            if (right <= left + (idx2Length[left] - arr[left])) {
                long long diff = right-left+1;
                res.push_back(diff*(diff+1)/2);
                continue;
            }

            // calculate difference using prefix sum
            long long tot = preSum[right] - (left==0?0:preSum[left-1]);

            // when left is in the middle of one segment
            if (arr[left] != 1) {
                long long diff = idx2Length[left] - arr[left] + 1;
                tot += diff*(diff+1)/2;
                tot -= idx2Length[left]*(idx2Length[left]+1)/2 - arr[left]*(arr[left]-1)/2;
            }
            res.push_back(tot);
        }

        return res;
    }
};