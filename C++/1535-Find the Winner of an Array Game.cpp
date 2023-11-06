class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int N = arr.size();
        int count = 0;
        int res = arr[0];
        
        for (int i=1; i<N; i++){
            if (arr[i] > res){
                count = 1;
                res = arr[i];
            } else {
                count++;
            }
            if (count == k){
                return res;
            }
        }
        return res;
    }
};