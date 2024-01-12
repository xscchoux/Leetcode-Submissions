class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int N = nums.size();
        vector<unordered_map<long, int>> hmap(N);
        int res = 0;
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                long diff = 1L*nums[i] - nums[j];
                if (diff < INT_MIN || diff > INT_MAX)
                    continue;
                
                // this is more time-consuming...
                
                // if (hmap[j].count(diff) > 0){
                //     res += hmap[j][diff];
                // } else {
                //     hmap[j][diff] = 0;
                // }
                // hmap[i][diff] += hmap[j][diff] + 1;
                
                int sum = 0;
                if (hmap[j].count(diff) > 0){
                    sum = hmap[j][diff];
                }
                hmap[i][diff] += sum + 1;
                res += sum;
            }
        }
        return res;
    }
};