class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        // There can be at most two majority numbers
        int res1 = 0, res2 = 0, count1 = 0, count2 = 0;
        
        for (int num:nums){
            if (num == res1) count1++;
            else if (num == res2) count2++;
            else if (count1 == 0){
                res1 = num;
                count1 = 1;
            } else if (count2 == 0){
                res2 = num;
                count2 = 1;
            } else{
                count1--;
                count2--;
            }
        }
        
        // Note that we cannot do
//         for (int n:nums){
//             if (count1 == 0){
//                 res1 = n;
//                 count1 += 1;
//             }else if (count2 == 0){
//                 res2 = n;
//                 count2 += 1;
//             }else if (res1 == n){
//                 count1 += 1;
//             }else if (res2 == n){
//                 count2 += 1;
//             }else{
//                 count1 -= 1;
//                 count2 -= 1;
//             }
//         }
        
        vector<int> ans;
        int c1 = 0, c2 = 0, val = nums.size()/3;
        
        for (int num:nums){
            if (num == res1) c1++;
            else if (num == res2) c2++;
        }

        if (c1 > val) ans.push_back(res1);
        if (c2 > val) ans.push_back(res2);
        
        return ans;
    }
};