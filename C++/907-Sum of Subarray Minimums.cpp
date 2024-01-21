class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int N = arr.size();
        int kMod = 1e9+7;
        vector<long> rightSmaller(N, N);
        vector<long> leftSmaller(N, -1);
        
        stack<int> stk1;
        for (int i=0; i<N; i++) {
            while (!stk1.empty() && arr[i] <= arr[stk1.top()]) {
                int ind = stk1.top();
                rightSmaller[ind] = i;
                stk1.pop();
            }
            stk1.push(i);
        }
        
        stack<int> stk2;
        for (int i=N-1; i>=0; i--) {
            while (!stk2.empty() && arr[i] < arr[stk2.top()]) {
                int ind = stk2.top();
                leftSmaller[ind] = i;
                stk2.pop();
            }
            stk2.push(i);
        }
        
        long res = 0;
        for (int i=0; i<N; i++) {
            res = res + arr[i]*((i-leftSmaller[i])%kMod)*(rightSmaller[i]-i)%kMod;
            res = res%kMod;
        }
        
        return (int)res;
    }
};