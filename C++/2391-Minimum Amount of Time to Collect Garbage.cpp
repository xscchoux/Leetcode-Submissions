class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        for (int i=1; i<travel.size(); i++){
            travel[i] += travel[i-1];
        }
        for (char c:"MPG"){
            int last = 0;
            for (int i = 0; i<garbage.size(); i++){
                int num = count(garbage[i].begin(), garbage[i].end(), c);
                res += num;
                if (num > 0) last = i;
            }
            if (last >= 1) res += travel[last-1];
        }
        return res;
    }
};