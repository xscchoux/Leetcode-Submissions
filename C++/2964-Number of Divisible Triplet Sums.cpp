class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        unordered_map<int, int> running2, running;
        int res = 0;
        
        for (int num:nums){
            for (auto [k2, v2]:running2){
                if ( (num+k2)%d == 0) res = res + v2;
            }
            for (auto [k1, v1]:running){
                running2[(k1+num)%d] += v1;
            }
            running[num%d]++;
        }
        
        return res;
    }
};