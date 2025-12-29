class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int left = 0, right = 0;
        int res = 0;
        for (int i=0; i<calories.size(); i++) {
            right += calories[i];
            if (i>=k-1) {
                int sum = right-left;
                if (sum > upper) {
                    res++;
                } else if (sum < lower) {
                    res--;
                }
            }
            if (i-k+1 >= 0) {
                left += calories[i-k+1];
            }
        }
        return res;
    }
};