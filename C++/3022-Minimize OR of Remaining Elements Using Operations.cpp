class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        // https://github.com/wisdompeak/LeetCode/tree/master/Greedy/3022.Minimize-OR-of-Remaining-Elements-Using-Operations
        int N = nums.size();
        vector<int> arr(N);
        int res = 0;
        for (int i=30; ~i; i--) {
            for (int j=0; j<N; j++) {
                arr[j] = arr[j]*2 + ((nums[j]>>i)&1);
            }
            if (canErase(arr, k)) {
                res = res*2;
            } else {
                for (int j=0; j<N; j++) {
                    arr[j] >>= 1;
                }
                res = res*2 + 1;
            }
        }
        return res;
    }
    
    bool canErase(vector<int>& arr, int k) {   
        int count = 0, N = arr.size();
        // count determines the number of operations needed to make bitwise OR of arr zero in the ith bit 
        for (int i=0; i<N; ){
            int curr = arr[i];
            int j = i;
            while (curr != 0) {
                count++;
                j++;
                if (j == N) break;
                curr = curr&arr[j];
            }
            i = j+1;
        }

        return count<=k;
    }
};