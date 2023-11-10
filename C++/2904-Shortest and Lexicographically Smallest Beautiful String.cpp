class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        deque<int> deque;
        int N = s.size();
        int longest = N;
        string res(N+1, '1');
        
        for (int i=0; i<N; i++){
            if (s[i] == '1'){
                deque.push_back(i);
            }
            if (deque.size() == k){
                int length = deque.back() - deque.front() + 1;
                if (length < longest){
                    longest = length;
                    res = s.substr(deque.front(), length);
                } else if (length == longest){
                    if (res > s.substr(deque.front(), length)){
                        res = s.substr(deque.front(), length);
                    }
                }
                deque.pop_front();
            }
        }
        
        return res.size()>N?"":res;
    }
};