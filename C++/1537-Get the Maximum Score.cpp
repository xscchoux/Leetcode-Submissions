// top down DP
using LL = long long;
class Solution {
public:
    int N1, N2, kMod = 1e9+7;
    LL dfs(vector<int>& nums1, vector<int>& nums2, int arrNum, int ind, vector<int>& mapping1, vector<int>& mapping2, vector<vector<LL>>& memo) {
        if ((arrNum == 1 && ind == N1) || (arrNum == 2 && ind == N2)) return 0;

        if (memo[ind][arrNum] != -1) return memo[ind][arrNum];

        if (arrNum == 1) {
            LL op1 = nums1[ind] + dfs(nums1, nums2, arrNum, ind+1, mapping1, mapping2, memo);
            LL op2 = mapping1[ind]!=-1?dfs(nums1, nums2, 2, mapping1[ind]+1, mapping1, mapping2, memo):0;
            return memo[ind][arrNum] = max(op1, op2);
        } else {
            LL op1 = nums2[ind] + dfs(nums1, nums2, arrNum, ind+1, mapping1, mapping2, memo);
            LL op2 = mapping2[ind]!=-1?dfs(nums1, nums2, 1, mapping2[ind]+1, mapping1, mapping2, memo):0;
            return memo[ind][arrNum] = max(op1, op2);
        }

        // Don't put kMod here. The maximum sum can be incorrectly evaluated if partial results have already been reduced modulo kMod
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        N1 = nums1.size();
        N2 = nums2.size();
        vector<int> mapping1(N1, -1), mapping2(N2, -1);
        vector<vector<LL>> memo(max(N1, N2), vector<LL>(3, -1));

        int i=0, j=0;
        while (i<N1 && j<N2) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                mapping1[i] = j;
                mapping2[j] = i;
                i++;
                j++;
            }
        }

        int val1 = dfs(nums1, nums2, 1, 0, mapping1, mapping2, memo)%kMod;
        int val2 = dfs(nums1, nums2, 2, 0, mapping1, mapping2, memo)%kMod;
        return max(val1, val2);
    }
};


// O(1) space, much faster
using LL = long long;
class Solution {
public:
    int N1, N2, kMod = 1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        N1 = nums1.size();
        N2 = nums2.size();
        LL dp1 = 0, dp2 = 0;
        int i=0, j=0;
        while (i<N1 || j<N2) {
            if (i<N1 && j<N2 && nums1[i] == nums2[j]) {
                dp1 = dp2 = max(dp1, dp2) + nums1[i];
                i++;j++;
            } else if ( j==N2 || (i<N1 && nums1[i] < nums2[j]) ) {
                dp1 += nums1[i];
                i++;
            } else {
                dp2 += nums2[j];
                j++;
            }
        }

        return max(dp1, dp2)%kMod;
    }
};