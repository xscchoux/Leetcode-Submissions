class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        int p = 1;
        for (int i=1; i<=1000; i++){
            if ( (i*i)%k == 0 ){
                p = i;  //  p: the smallest int in which (p*p)%k==0 
                break;
            }
        }

        unordered_map<int, unordered_map<int, int>> hmap;
        int diff = 0, vowel = 0;
        hmap[0][0] = 1;
        int res = 0;
        
        for (char c:s){
            if (vowelSet.find(c) != vowelSet.end()){
                diff++;
                vowel++;
            }else{
                diff--;
            }
            res += hmap[diff][vowel%p];
            hmap[diff][vowel%p]++;
        }
        
        return res;
    }
};