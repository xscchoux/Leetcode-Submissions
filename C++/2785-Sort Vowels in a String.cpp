class Solution {
    // slower ...
    
    // bool isVowel(char c){
    //     string vowels = "aeiouAEIOU";
    //     return count(vowels.begin(), vowels.end(), c) > 0;
    // }
    
    // also slower ...
    
//     bool isVowel(char c) {
//         string vowels = "aeiouAEIOU";
//         return vowels.find(c) != string::npos;
//     }
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }

public:
    string sortVowels(string s) {
        vector<char> arr;
        for (char c:s){
            if (isVowel(c)){
                arr.push_back(c);
            }
        }
        
        sort(arr.begin(), arr.end());
        
        string res;
        int ind = 0;
        for (char c:s){
            if (isVowel(c)){
                res += arr[ind];
                ind++;
            } else {
                res += c;
            }
        }
        return res;
    }
};