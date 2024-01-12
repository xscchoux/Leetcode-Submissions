class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int, int>> arr;
        for (int i=0; i<startTime.size(); i++){
            arr.push_back(make_pair(endTime[i], i));
        }
        
        sort(arr.begin(), arr.end());

        map<int, int> preMap {{0, 0}};
        int preVal = 0;
        
        for (auto v:arr) {
            int end = v.first;
            int index = v.second;
            int profits = profit[index];
            int start = startTime[index];
            
            auto it = preMap.upper_bound(start);
            it = prev(it);
            // if (it != preMap.begin()) it = prev(it);
            
            int currVal = preMap[it->first] + profits;
            
            if (currVal > preVal){
                preMap[end] = currVal;
                preVal = currVal;
            }
        }
        return preMap.rbegin()->second;
    }
};