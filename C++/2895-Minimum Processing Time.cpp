class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < tasks.size(); i=i+4){
            res = max(res, processorTime[i/4] + tasks[i]);
        }
        return res;
    }
};