class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        int pre = 0;
        for (int i = 0; i< pref.size(); i++){
            res.push_back(pref[i]^pre);
            pre = pref[i];
        }
        return res;
    }
};