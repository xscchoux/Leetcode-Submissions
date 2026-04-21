class Solution {
public:
    int maximumTeamSize(vector<int>& startTime, vector<int>& endTime) {
        int N = startTime.size(), res = 0;
        
        vector<int> sortedStart = startTime;
        vector<int> sortedEnd = endTime;

        sort(begin(sortedStart), end(sortedStart));
        sort(begin(sortedEnd), end(sortedEnd));

        for (int i=0; i<N; i++) {
            int upperIdx = upper_bound(begin(sortedStart), end(sortedStart), endTime[i]) - begin(sortedStart);
            int lowerIdx = lower_bound(begin(sortedEnd), end(sortedEnd), startTime[i]) - begin(sortedEnd);            
            res = max(res, upperIdx - lowerIdx);
        }

        return res;
    }
};