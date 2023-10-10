class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size(), res = N;
        // assigning the elements from nums to sortedUnique
        set<int> sortedUnique(nums.begin(), nums.end());
        vector<int> arr(sortedUnique.begin(), sortedUnique.end());

        int j = 0;
        for (int i=0; i<arr.size(); i++){
            if (arr[i] - arr[j] >= N){
                j += 1;
            }
            res = min(res, N-(i-j+1));
        }
        return res;
    }
};