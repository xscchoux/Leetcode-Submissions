// First AC
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int res = 3, curr = 2, N = nums.size();
        // without replacing
        for (int i=2; i<N; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr++;
            } else {
                curr = 2;
            }
            res = max(res, curr);
        }

        // length of longest arithmetic subarray ending at i-1 using fixed differences
        vector<pair<int, int>> left(N);
        left[0] = {100000, 0};  // { diff, length }
        for (int i=1; i<N; i++) {
            int diff = nums[i] - nums[i-1];
            if (diff == left[i-1].first) {
                left[i] = {left[i-1].first, left[i-1].second+1};
            } else {
                left[i] = {diff, 1};
            }
        }

        // length of longest arithmetic subarray starting at i+1.
        vector<pair<int, int>> right(N);
        right[N-1] = {100000, 0}; // { diff, length }
        for (int i=N-2; i>=0; i--) {
            int diff = nums[i+1] - nums[i];
            if (diff == right[i+1].first) {
                right[i] = {right[i+1].first, right[i+1].second+1};
            } else {
                right[i] = {diff, 1};
            }
        }
        
        
        for (int i=0; i<N; i++) {
            
            // check left neighbors and right neighbors of nums[i] 
            if (i >= 2) {
                int diff = nums[i] - nums[i-2];
                if (diff%2 == 0) {
                    int half = diff/2;
                    int leftLength = ((left[i-2].first == half)? left[i-2].second:0);
                    int rightLength = ((right[i].first == half)? right[i].second:0);
                    res = max(res, 3 + leftLength + rightLength);  
                }
            }

            // extend only left, and consider only the case when length >= 4
            if (i > 2) res = max(res, 2 + left[i-1].second);
            // extend only right, and consider only the case when length >= 4
            if (i <= N-3) res = max(res, 2 + right[i+1].second);
        }

        return res;
    }
};


// No need to use pair<int, int>
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int res = 3, curr = 2, N = nums.size();
        // without replacing
        for (int i=2; i<N; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr++;
            } else {
                curr = 2;
            }
            res = max(res, curr);
        }

        // length of longest arithmetic subarray ending at i-1 using fixed differences
        vector<int> left(N);
        left[0] = 0;
        left[1] = 1;
        for (int i=2; i<N; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                left[i] = left[i-1] + 1;
            } else {
                left[i] = 1;
            }
        }

        // length of longest arithmetic subarray starting at i+1.
        vector<int> right(N);
        right[N-1] = 0;
        right[N-2] = 1;
        for (int i=N-3; i>=0; i--) {
            if (nums[i] - nums[i+1] == nums[i+1] - nums[i+2]) {
                right[i] = right[i+1] + 1;
            } else {
                right[i] = 1;
            }
        }
        
        
        for (int i=0; i<N; i++) {

            // check left neighbors and right neighbors of nums[i] 
            if (i >= 2) {
                int diff = nums[i] - nums[i-2];
                if (diff%2 == 0) {
                    int half = diff/2;
                    int leftLength = ((i>=3 && nums[i-2] - nums[i-3] == half)? left[i-2]:0);
                    int rightLength = ((i<N-1 && nums[i+1] - nums[i] == half)? right[i]:0);
                    res = max(res, 3 + leftLength + rightLength);  
                }
            }

            // extend only left, and consider only the case when length >= 4
            if (i > 2) res = max(res, 2 + left[i-1]);
            // extend only right, and consider only the case when length >= 4
            if (i <= N-3) res = max(res, 2 + right[i+1]);
        }

        return res;
    }
};