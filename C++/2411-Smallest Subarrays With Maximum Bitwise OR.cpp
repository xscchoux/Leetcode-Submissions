class Solution {
public:
    int N;
    bool check(vector<int>& curr, int rightVal) {
        int idx = 0;
        while (rightVal > 0) {
            if (curr[idx++] == 1 && rightVal%2 == 1) return false;
            rightVal /= 2;
        }

        return true;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        this->N = nums.size();
        vector<int> res(N), curr(31, 0);
        int right = N-1;

        for (int i=N-1; i>=0; i--) {
            int tmpVal = nums[i];
            int idx = 0;
            while (tmpVal > 0) {
                curr[idx++] += tmpVal%2;
                tmpVal /= 2;
            }

            while (right > i && check(curr, nums[right])) {
                int val = nums[right];
                int idx = 0;
                while (val > 0) {
                    curr[idx++] -= val%2;
                    val /= 2;
                }
                right--;
            }

            res[i] = right-i+1;
        }

        return res;
    }
};