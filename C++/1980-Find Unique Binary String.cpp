class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        for (int i=0; i<nums.size(); i++){
            char curr = nums[i][i];
            res += (curr == '0')?'1':'0';
        }
        return res;
    }
};



// recursive
class Solution {
public:
    unordered_set<string> banned;
    int N;
    
    string dfs(string current){
        if (current.size() == N){
            if (!banned.count(current)) return current;
            return "";
        }
        string str = "01";
        for (char c:str){
            string val = dfs(current+c);
            if (!val.empty()) return val;
        }
        return "";
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        this->N = nums[0].size();
        for (string num:nums){
            banned.insert(num);
        }
        return dfs("");
    }
};