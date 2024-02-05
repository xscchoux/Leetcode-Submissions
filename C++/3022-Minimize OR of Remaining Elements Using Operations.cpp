using LL = long long;
class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
// From Huifeng Guan
// https://github.com/wisdompeak/LeetCode/blob/master/Greedy/3022.Minimize-OR-of-Remaining-Elements-Using-Operations/3022.Minimize-OR-of-Remaining-Elements-Using-Operations.cpp

        int N = nums.size();
        LL res = 0;
        vector<int> arr(N);
        
        for (int t=30; ~t; t--) {
            for (int i=0; i<N; i++) arr[i] = 2*arr[i] + ((nums[i]>>t)&1);
                    
            if(checkOK(arr, k)) {
                res = 2*res;
            } else {
                for (int i=0; i<N; i++){
                    arr[i] >>= 1;
                }
                res = 2*res+1;
            }
        }
        return res;
    }
    bool checkOK(vector<int>&arr, int k) {
        int N = arr.size();
        int count = 0;
        for (int i=0;i<N;) {
            int curr = arr[i];
            int j = i;
            while (curr!=0) {
                j++;
                count++;
                if (j == N ) break;
                curr = curr&arr[j];
            }
            i = j+1;
        }
        return (count!=N && count<=k);
    }
};