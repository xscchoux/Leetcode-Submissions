using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    bool differByOne(vector<string>& dict) {
        // Rabin-Karp
        vector<LL> hash;
        
        for (string &s:dict) {
            LL num = 0;
            for (char w:s) {
                num = (num*26 + (w-'a'))%kMod;
            }
            hash.push_back(num);
        }


        int N = dict.size(), wordLen = dict[0].size();
        unordered_map<LL, unordered_set<int>> hmap; // hash:index
        for (int i=0; i<N; i++) {
            LL currHash = hash[i];
            LL coefficient = 1;
            for (int j=wordLen-1; j>=0; j--) {
                LL newHash = ((currHash - (dict[i][j]-'a')*coefficient)%kMod + kMod)%kMod;
                if (hmap.contains(newHash)) {
                    for (int index:hmap[newHash]) {
                        if (index != i && dict[i].substr(0, j) == dict[index].substr(0, j) && dict[i].substr(j+1, N-1-j) == dict[index].substr(j+1, N-1-j)) {
                            return true;
                        }
                    }
                }
                hmap[newHash].insert(i);
                coefficient = (coefficient*26)%kMod;
            }
        }

        return false;
    }
};



// iterate over wordLen first, better!
using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    bool differByOne(vector<string>& dict) {
        // Rabin-Karp
        vector<LL> hash;
        
        for (string &s:dict) {
            LL num = 0;
            for (char w:s) {
                num = (num*26 + (w-'a'))%kMod;
            }
            hash.push_back(num);
        }


        int N = dict.size(), wordLen = dict[0].size();
        LL coefficient = 1;
        for (int j=wordLen-1; j>=0; j--) {
            unordered_map<LL, unordered_set<int>> hmap; // hash:index
            for (int i=0; i<N; i++) {
                LL currHash = hash[i];
                LL newHash = ((currHash - (dict[i][j]-'a')*coefficient)%kMod + kMod)%kMod;
                if (hmap.contains(newHash)) {
                    for (int index:hmap[newHash]) {
                        if (index != i && dict[i].substr(0, j) == dict[index].substr(0, j) && dict[i].substr(j+1, N-1-j) == dict[index].substr(j+1, N-1-j)) {
                            return true;
                        }
                    }
                }
                hmap[newHash].insert(i);
            }
            coefficient = (coefficient*26)%kMod;
        }
        return false;
    }
};