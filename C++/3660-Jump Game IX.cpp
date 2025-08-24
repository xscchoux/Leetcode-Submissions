// https://leetcode.com/problems/jump-game-ix/solutions/7115326/using-prefix-suffix-array-explained-in-depth-c-python-java/
// O(N)
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefixMax(N, 0), suffixMin(N, INT_MAX);

        prefixMax[0] = nums[0];
        for (int i=1; i<N; i++) {
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }

        suffixMin[N-1] = nums[N-1];
        for (int i=N-2; i>=0; i--) {
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }

        vector<int> res(N);
        res[N-1] = prefixMax.back();
        for (int i=N-2; i>=0; i--) {
            res[i] = prefixMax[i];
            // when max prefix value > smallest suffix value, we can jump to (larger left)->(smaller right)->(larger right)
            if (suffixMin[i+1] < prefixMax[i]) {  
                res[i] = res[i+1];
            }
        }

        return res;
    }
};