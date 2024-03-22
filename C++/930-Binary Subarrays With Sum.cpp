class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0, res = 0;
        vector<int> zeroArr;
        
        for (int num:nums) {
            if (num == 0) cnt++;
            else {
                zeroArr.push_back(cnt);
                cnt = 0;
            }
        }
        zeroArr.push_back(cnt);

        if (goal > 0) {
            for (int i=0; (i+goal)<zeroArr.size(); i++) {
                res += (zeroArr[i]+1)*(zeroArr[i+goal]+1);
            }
        } else {
            for (int n:zeroArr) {
                res += n*(n+1)/2;
            }
        }
        
        return res;
    }
};