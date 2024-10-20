vector<int> smallestDivisor(1000001, -1);
bool flag = false;

void divisors() {
    for (int i=2; i<=1e6; i++) {
        for (int j=2; j*j<=i; j++) {
            if (i%j == 0) {
                smallestDivisor[i] = j;
                break;
            }
        }
    }
}

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size(), res = 0;
        if (!flag) {
            flag = true;
            divisors();
        }

        for (int i=N-2; i>=0; i--) {
            if (nums[i] > nums[i+1]) {
                while (nums[i] > nums[i+1]) {
                    int d = smallestDivisor[nums[i]];
                    if (d == -1) return -1;
                    nums[i] = smallestDivisor[nums[i]];
                }
                res++;
            }
        }

        return res;
    }
};