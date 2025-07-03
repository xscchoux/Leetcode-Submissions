// brute-force simulation
class Solution {
public:
    char kthCharacter(int k) {
        string curr = "a";

        while (curr.size() < k) {
            string newString = "";
            for (int i=0; i<curr.size(); i++) {
                newString.push_back( static_cast<char>('a' + ((curr[i]-'a')+1)%26) );
            }
            curr = curr + newString;
        }
        return curr[k-1];
    }
};


// O(logk), clever solution
class Solution {
public:
    char kthCharacter(int k) {
        int appendCnt = 0;

        while (k != 1) {
            int t = __lg(k);  //  ⌊log₂(k)⌋
            if (k == (1<<t)) {
                t -= 1;
            }
            k -= (1<<t);
            appendCnt++;
        }

        return 'a' + appendCnt;
    }
};