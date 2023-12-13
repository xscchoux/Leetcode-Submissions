class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int N = word.size();
        int start = 0;
        int res = 0;
        
        auto cal = [&word, k](int start, int end) {
            int count = 0;
            for (int t=1; t<=26; t++){
                int window = t*k;
                if (window > end-start+1) break;
                vector<int> tmp(26, 0);
                for (int i=start; i<start+window; i++){
                    tmp[word[i]-'a']++;
                }
                int valid = 0;
                for (int i=0; i<26; i++){
                    if (tmp[i] == k){
                        valid++;
                    }
                }
                if (valid == t) count++;

                for (int i=start+window; i<=end; i++){
                    tmp[word[i]-'a']++;
                    if (tmp[word[i]-'a'] == k) valid++;
                    else if (tmp[word[i]-'a'] == k+1) valid--;
                    
                    tmp[word[i-window]-'a']--;
                    if (tmp[word[i-window]-'a'] == k) valid++;
                    else if (tmp[word[i-window]-'a'] == k-1) valid--;
                    
                    if (valid == t) count++;
                }
            }
            return count;
        };
        
        for (int i=1; i<N; i++){
            if (abs(word[i]-word[i-1]) > 2){
                res += cal(start, i-1);
                start = i;
            }
        }
        res += cal(start, N-1);
        
        return res;
    }
};