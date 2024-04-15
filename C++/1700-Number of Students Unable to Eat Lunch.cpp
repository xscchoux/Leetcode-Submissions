class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int, int> count;
        int res = sandwiches.size();
        for (int s:students) count[s]++;
        
        for (int s:sandwiches) {
            if (count[s] > 0) {
                count[s]--;
                res--;
            } else {
                break;
            }
        }
        
        return res;
    }
};