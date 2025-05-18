class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int N = nums.size();
        vector<int> sortedNums = nums;
        unordered_map<int, int> hmap; // number to index
        for (int i=0; i<N; i++) hmap[nums[i]] = i;

        sort(begin(sortedNums), end(sortedNums), [&](int a, int b) {
            int totA = 0, totB = 0, tmpA = a, tmpB = b;
            while (tmpA > 0) {
                totA += tmpA%10;
                tmpA/=10;
            }

            while (tmpB > 0) {
                totB += tmpB%10;
                tmpB/=10;
            }
            
            return (totA < totB) || (totA == totB && a < b); 
        });

        int res = 0;
        for (int i=0; i<N; i++) {
            if (nums[i] != sortedNums[i]) {
                int correctVal = sortedNums[i];
                int currIdx = hmap[correctVal];

                hmap[nums[i]] = currIdx;
                hmap[correctVal] = i;

                swap(nums[i], nums[currIdx]);

                res++;
            }
        }

        return res;
    }
};