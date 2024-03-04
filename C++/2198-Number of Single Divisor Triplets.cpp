using LL = long long;
class Solution {
public:
    long long singleDivisorTriplet(vector<int>& nums) {
        unordered_map<int, LL> hmap;
        LL res = 0;
        for (int num:nums) hmap[num]++;
        
        vector<int> keys; 
        for (auto &kv:hmap) {
            keys.push_back(kv.first);
        }
        
        int N = keys.size();
        auto isTriplet = [](int a, int b, int c) {
            return (bool((a+b)%c) + bool((b+c)%a) + bool((a+c)%b)) == 2;
        };
            
            
        for (int i=0; i<N; i++) {
            for (int j=i; j<N; j++) {
                for (int k=j; k<N; k++) {
                    if (isTriplet(keys[i], keys[j], keys[k])) {
                        if (keys[i] == keys[j]) {
                            res += hmap[keys[i]]*(hmap[keys[i]]-1)*hmap[keys[k]]/2;
                        } else if (keys[j] == keys[k]) {
                            res += hmap[keys[i]]*hmap[keys[j]]*(hmap[keys[j]]-1)/2;
                        } else {
                            res += hmap[keys[i]]*hmap[keys[j]]*hmap[keys[k]];
                        }
                    }
                }
            }
        }
        
        return res*6;
    }
};