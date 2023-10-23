class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        int satisfied = 0;
        for (char c:t){
            tMap[c] += 1;
        }
        
        // for (const auto& kv : tMap) {
        //     cout << "Key: " << kv.first << ", Value: " << kv.second << endl;
        // }
        
        unordered_map<char, int> sMap;
        int left = 0;
        int start = 0, end = s.size();
        int tSize = tMap.size(); // we need this because the number of keys in tMap can change
        
        for (int i=0; i<s.size(); i++){
            sMap[s[i]] += 1;
            if (sMap[s[i]] == tMap[s[i]]){
                satisfied += 1;
            }
            while (satisfied == tSize){
                if (end-start+1 > i-left+1){
                    start = left;
                    end = i;
                }
                sMap[s[left]] -= 1;
                if (sMap[s[left]] < tMap[s[left]]){
                    satisfied -= 1;
                }
                left++;
            }
        }
        
        return (end-start == s.size())?"":s.substr(start,end-start+1);
    }
};