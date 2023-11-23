class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> hmap;
        vector<int> res;
        
        for (int r = nums.size() - 1; r >=0 ; r--){
            for (int c = 0; c < nums[r].size(); c++){
                hmap[r+c].push_back(nums[r][c]);
            }
        }
        
        int diagonal = 0;
        
        while (hmap.find(diagonal) != hmap.end()){
            for (int num:hmap[diagonal]){
                res.push_back(num);
            }
            diagonal++;
        }
        return res;
    }
};