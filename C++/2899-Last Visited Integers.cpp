class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int k = 0;
        vector<int> num_reverse;
        vector<int> res;
        for (string w:words){
            if (w == "prev"){
                k++;
                if ( num_reverse.size() < k){
                    res.push_back(-1);
                }else {
                    res.push_back(num_reverse[num_reverse.size()-k]);
                }
            } else{
                k = 0;
                num_reverse.push_back(stoi(w));
            }
        }
        return res;
    }
};