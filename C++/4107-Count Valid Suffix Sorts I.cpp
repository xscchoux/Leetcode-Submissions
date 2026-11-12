class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int N = nums.size();
        vector<int> tmp1 = nums, tmp2 = target;
        sort(begin(tmp1), end(tmp1));
        sort(begin(tmp2), end(tmp2));
        if (tmp1 != tmp2) return 0;

        vector<bool> nonIncreasing(N, false);
        nonIncreasing[N-1] = true;
        for (int i=N-2; i>=0; i--) {
            if (target[i] >= target[i+1]) {
                nonIncreasing[i] = true;
            } else {
                break;
            }
        }

        int res = 0;
        for (int i=0; i<N; i++) {
            if (nonIncreasing[i]) {
                res++;
            }
            if (nums[i] != target[i]) {
                break;
            }
        }

        return res;
    }
};