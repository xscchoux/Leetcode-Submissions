class Solution {
public:
    int N;
    bool isOK(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(N+1);
        for (int i=0; i<k; i++) {
            auto &q = queries[i];
            int u = q[0], v = q[1], val = q[2];
            diff[u] -= val;
            diff[v+1] += val;
        }
        int running = 0;
        for (int i=0; i<N; i++) {
            running += diff[i];
            if (nums[i] + running > 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        N = nums.size();
        int left = 0, right = queries.size();
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(nums, queries, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(nums, queries, left)) {
            return left;
        } else if (isOK(nums, queries, right)) {
            return right;
        } else {
            return -1;
        }

        return true;        
    }
};



// O(n), clever line sweep solution, kinda hard
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(), curr = 0, k = 0;
        vector<int> diff(N+1, 0);

        for (int i=0; i<N; i++) {
            while (diff[i] + curr + nums[i] > 0) {
                k++;
                if (k > queries.size()) return -1;

                int left = queries[k-1][0], right = queries[k-1][1], val = queries[k-1][2];
                if (right >= i) {
                    diff[max(left, i)] -= val;
                    diff[right+1] += val; 
                }
            }
            curr += diff[i];
        }

        return k;
    }
};