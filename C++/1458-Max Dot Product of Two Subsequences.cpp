class Solution {
public:
    
    static bool custom_compare(int a, int b){
        return abs(a)<abs(b);
    }
    
// The custom_compare function needs to be static when used as a custom comparison function for std::sort() because non-static member functions have an implicit this pointer as their first argument, which refers to the instance of the class they belong to. The std::sort() function expects a comparison function with two arguments, not three (the two elements being compared and the implicit this pointer).
        
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j] : max product of nums1[:i+1], nums2[:j+1]
        // dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+nums1[i]*nums2[j])
        
        int N1 = nums1.size(), N2 = nums2.size();
        vector<vector<int>>dp = vector(N1+1, vector(N2+1, 0));
        
        for (int i = 1; i <= N1; i++){
            for (int j = 1; j <= N2; j++){
                dp[i][j] = max( max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + nums1[i-1]*nums2[j-1] );
            }
        }
        
        if (dp[N1][N2] > 0) return dp[N1][N2];
        else{
            sort(nums1.begin(), nums1.end(), custom_compare);
            sort(nums2.begin(), nums2.end(), custom_compare);
            return nums1[0]*nums2[0];
        }
    }
};