class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int N = l.size();
        vector<bool> res;
        for (int i=0; i<N; i++){
            vector<int> tmp(nums.begin()+l[i], nums.begin()+r[i]+1);  //  common convention in C++ known as a half-open range
            sort(tmp.begin(), tmp.end());
            bool change = false;
            for (int k = 2; k < tmp.size(); k++){
                if (tmp[k] - tmp[k-1] != tmp[k-1] - tmp[k-2]){
                    change = true;
                    break;
                }
            }
            if (!change){
                res.push_back(true);
            } else{
                res.push_back(false);
            }
        }
        
        return res;
    }
};