/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubstring = function(s, k) {
    
    let sSet = new Set(s);
    let counter = new Map();
    let res = 0;
    for (let char of s){
        counter.set(char, (counter.get(char)||0)+1 );
    }

    for (let char of sSet){
        if(counter.get(char) < k){
            for (let sub of s.split(char)){
                res = Math.max(res, longestSubstring(sub, k));
            }
            return res;
        }
    }
    return s.length;
};