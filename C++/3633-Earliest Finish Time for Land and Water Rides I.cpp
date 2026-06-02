class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res = INT_MAX;
        
        for (int i=0; i<landStartTime.size(); i++) {
            int landFinishTime = landStartTime[i] + landDuration[i];
            for (int j=0; j<waterStartTime.size(); j++) {
                // land -> water
                 int endTime = max(landFinishTime, waterStartTime[j]) + waterDuration[j];
                 res = min(res, endTime);

                 // water -> land
                 int waterFinishTime = waterStartTime[j] + waterDuration[j];
                 int endTime2 = max(waterFinishTime, landStartTime[i]) + landDuration[i];
                 res = min(res, endTime2);
            }
        }

        return res;
    }
};