class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int durationCnt = 0;
        
        // for the last free time span
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);

        int N = startTime.size(), res = 0, totDuration = 0;

        // similar to sliding window. Keep a window of k meetings
        for (int i=0; i<N; i++) {
            if (durationCnt == 0) {
                res = max(res, startTime[i]);
            } else if (durationCnt <= k){
                res = max(res, startTime[i] - totDuration);
            } else {
                totDuration -= (endTime[i-k-1] - startTime[i-k-1]);
                res = max(res, startTime[i] - endTime[i-k-1] - totDuration);
            }
            durationCnt++;
            totDuration += (endTime[i]-startTime[i]);
        }

        return res;
    }
};