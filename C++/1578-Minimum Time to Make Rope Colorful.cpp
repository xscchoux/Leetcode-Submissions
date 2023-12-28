class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int left = 0;
        int res = 0;
        for (int i=0; i<=colors.size(); i++){
            if (colors[i] != colors[left]){
                if (i-1 > left){
                    res += accumulate(neededTime.begin()+left, neededTime.begin()+i, 0)- *max_element(neededTime.begin()+left, neededTime.begin()+i);
                }
                left = i;
            }
        }
        return res;
    }
};