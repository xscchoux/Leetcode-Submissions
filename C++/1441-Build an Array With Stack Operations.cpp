class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int targetIdx = 0;
        for (int i=1; i<=n; i++){
            if (targetIdx == target.size()) break;
            
            if (i < target[targetIdx]){
                res.push_back("Push");
                res.push_back("Pop");
            }else {
                res.push_back("Push");
                targetIdx++;
            }
        }
        return res;
    }
};