class Solution {
public:
    int minChanges(string s) {
        // first try
        // int count = 0;
        // int res = 0;
        // for (int i=0; i<s.size(); i++){
        //     if (i == 0 || s[i] != s[i-1]){
        //         if (count%2 == 0){
        //             count = 1;
        //         }else{
        //             res++;
        //             count = 0;
        //         }
        //     }else{
        //         count++;
        //     }
        // }
        // return res;
        
        // better
        int res = 0;
        for (int i=1; i<s.size(); i+=2){
            if (s[i] != s[i-1]) res++;
        }
        return res;
    }
};