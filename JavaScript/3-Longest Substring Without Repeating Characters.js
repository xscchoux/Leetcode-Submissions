/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let hmap = new Map();
    let start = 0;
    let res = 0;
    for (let i=0; i<s.length; i++){
        while (hmap.has(s[i])){
            hmap.delete(s[start]);
            start += 1;
        }
        hmap.set(s[i], (hmap.get(s[i])||0)+1);
        res = Math.max(res, hmap.size);
    }
    
    return res;
    
};