class Solution {
private:
    vector<bool> isPrime;
public:
    Solution() {
        isPrime.resize(101, true);
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; p * p <= 100; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= 100; i += p) {
                    isPrime[i] = false;
                }
            }
        }        
    }

    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> arr;
        int N = nums.size();
        int mi = N-1, mx = 0; 
        for (int i=0; i<nums.size(); i++) {
            if (isPrime[nums[i]]) {
                mi = min(i, mi);
                mx = max(i, mx);
            }
        }
        return mx-mi;
    }
};