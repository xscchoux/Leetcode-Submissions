// Count reversed pairs
constexpr int kMod = 1e9+7;
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int N = nums.size();

        // c2: count of previous elements in the range [a, b] inclusive
        // c3: count of previous elements greater than b
        long long res = 0, c2 = 0, c3 = 0;

        for (int i=0; i<N; i++) {
            if (nums[i] < a) {
                res = (res + c2 +c3)%kMod;
            } else if (nums[i] <= b) {
                res = (res + c3)%kMod;
                c2++;
            } else {
                c3++;
            }
        }
        
        return res;
    }
};