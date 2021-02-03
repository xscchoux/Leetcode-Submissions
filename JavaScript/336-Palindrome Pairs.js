/**
 * @param {string[]} words
 * @return {number[][]}
 */
var palindromePairs = function(words) {
    let wordDict = new Map();
    let res = new Array();
    
    for (const [index, word] of words.entries()){
        wordDict.set(word, index);
    }
    
    let isPalindrome = (word) => {
        let left = 0, right = word.length-1;
        while (left < right){
            if (word[left] !== word[right]){
                return false;
            }else{
                left++;
                right--;
            }
        }
        return true;
    };
    
    
    for (let [index, word] of words.entries()){
        for (let split=0; split<=word.length; split++){
            let leftWord = word.slice(0, split), rightWord = word.substring(split);
            if (isPalindrome(leftWord)){
                let reverseRightWord = rightWord.split("").reverse().join("");
                if (wordDict.has(reverseRightWord) && index !== wordDict.get(reverseRightWord)){
                    res.push([wordDict.get(reverseRightWord), index]);
                }
            }
            if (rightWord.length > 0 && isPalindrome(rightWord)){
                let reverseLeftWord = leftWord.split("").reverse().join("");
                if (wordDict.has(reverseLeftWord)){
                    res.push([index, wordDict.get(reverseLeftWord)]);
                }
            }
        }
    }
    return res;
};