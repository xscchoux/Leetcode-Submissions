class Solution {
public:
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        long kMod = 1e9+7;
        
        for (int k = 1; k<n; k++){
            long nxt_a = (e + i + u)%kMod;
            long nxt_e = (a + i)%kMod;
            long nxt_i = (e + o)%kMod;
            long nxt_o = i%kMod;
            long nxt_u = (i + o)%kMod;
            a = nxt_a; e = nxt_e; i = nxt_i; o = nxt_o; u = nxt_u;
        }
        return (a+e+i+o+u)%kMod;
    }
};



class Solution {
public:
    long kMod = 1e9+7;
    // DFS    
    long dfs(char c, int remain, unordered_map<char, vector<char>>& hmap, vector<vector<int>>& memo){
        if (remain == 1) return 1;
        if (memo[remain][c-'a'] != -1) return memo[remain][c-'a'];
        
        long tot = 0;
        for (char nxt:hmap[c]){
            tot = (tot + dfs(nxt, remain-1, hmap, memo))%kMod;
        }
        memo[remain][c-'a'] = tot;
        return tot;
    }
    
    int countVowelPermutation(int n) {
        unordered_map<char, vector<char>> hmap = {
            {'a',{'e'}}, 
            {'e',{'a', 'i'}}, 
            {'i',{'a','e','o','u'}}, 
            {'o',{'i','u'}}, 
            {'u',{'a'}} 
        };
        vector<vector<int>> memo = vector(n+1, vector(26, -1));
        long res=0;
        for (char c:string("aeiou")){
            res = (res + dfs(c, n, hmap, memo))%kMod;
        }
        return res;
    }
};