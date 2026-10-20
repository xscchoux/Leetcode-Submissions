class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int N = nums.size();
        
        vector<int> divisors;
        // find divisors
        for (int d = 1; d*d <= N; d++) {
            if (N%d == 0) {
                if (d*d == N) {
                    divisors.push_back(d);
                } else {
                    divisors.push_back(d);
                    divisors.push_back(N/d);
                }
            }
        }

        int res= 0;
        for (int k:divisors) {
            // check all segments
            bool found = true;
            int preMax = INT_MIN;
            for (int start=0; start+k<=N; start+=k) {
                // count drop points
                int cnt = 0;
                for (int i=start+1; i<start+k; i++) {
                    if (nums[i] < nums[i-1]) {
                        cnt++;
                    }
                    if (cnt > 1) {
                        found = false;
                        break;
                    }
                }

                // when there's one drop point
                if (cnt > 0 && nums[start+k-1] > nums[start]) {
                    found = false;
                }

                if (!found) {
                    break;
                }
                
                int currMax = INT_MIN, currMin = INT_MAX;
                for (int i=start; i< start+k; i++) {
                    currMax = max(currMax, nums[i]);
                    currMin = min(currMin, nums[i]);
                }

                if (currMin < preMax) {
                    found = false;
                    break;
                }

                preMax = currMax;

            }
            if (found) {
                res += k;
            }

        }
        return res;
    }
};