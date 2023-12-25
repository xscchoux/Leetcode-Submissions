using LL = long long;
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(), hFences.end());
        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);
        sort(vFences.begin(), vFences.end());
        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);
        int kMod = 1e9+7;
        int res = -1;
        unordered_set<int> lenSet;
        for (int i=0; i<hFences.size(); i++){
            for (int j=i+1; j<hFences.size(); j++){
                lenSet.insert(hFences[j] - hFences[i]);
            }
        }
        
        for (int i=0; i<vFences.size(); i++){
            for (int j=i+1; j<vFences.size(); j++){
                if (lenSet.find(vFences[j] - vFences[i]) != lenSet.end()){
                    res = max(res,vFences[j]-vFences[i]);
                }
            }
        }
        return (res == -1)?-1:1LL*res*res%kMod;
    }
};