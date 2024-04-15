class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        // https://github.com/wisdompeak/LeetCode/tree/master/Math/1131.Maximum-of-Absolute-Value-Expression
        // (a+b+i, a-b+i, -a+b+i, -a-b+i, a+b-i, a-b-i, -a+b-i, -a-b-i)
        
        int N = arr1.size();
        vector<vector<int>> arr(8);
        for (int i=0; i<N; i++) {
            arr[0].push_back(arr1[i]+arr2[i]+i);
            arr[1].push_back(arr1[i]-arr2[i]+i);
            arr[2].push_back(-arr1[i]+arr2[i]+i);
            arr[3].push_back(-arr1[i]-arr2[i]+i);
            arr[4].push_back(arr1[i]+arr2[i]-i);
            arr[5].push_back(arr1[i]-arr2[i]-i);
            arr[6].push_back(-arr1[i]+arr2[i]-i);
            arr[7].push_back(-arr1[i]-arr2[i]-i);
        }
        
        int diff = 0;
        
        for (auto &a:arr) {
            int mx = *max_element(a.begin(), a.end());
            int mn = *min_element(a.begin(), a.end());
            diff = max(diff, mx-mn);
        }
        
        return diff;
    }
};