class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int N = dist.size();
        vector<int> arr;
        for (int i=0; i<N; i++){
            arr.push_back(ceil((float)dist[i]/speed[i]));
        }
        sort(arr.begin(), arr.end());
        
        int curTime = 0;
        int count = 0;
        
        for (int x:arr){
            if (curTime < x){
                curTime++;
                count++;
            } else {
                return count;
            }
        }
        return N;        
    }
};