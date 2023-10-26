class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        int kMod = 1e9+7;
        long res = 0;
        
        for (int i=0; i<arr.size(); i++){
            if (dp.count(arr[i])) continue;
            dp[arr[i]] = 1;
            for (int j=0; j<i; j++){
                if (arr[i]%arr[j] == 0 && dp.count(arr[i]/arr[j])){
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]]*dp[arr[i]/arr[j]])%kMod;
                }
            }
            res = (res + dp[arr[i]])%kMod;
        }
        return res;
    }
};