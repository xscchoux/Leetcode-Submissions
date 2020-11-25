/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstringTwoDistinct = function(s) {
    let hmap = new Map();
    let left = 0;
    let res = 0;
    
    for (let i=0; i<s.length; i++){
        hmap.set(s[i], (hmap.get(s[i])||0)+1 );
        while (hmap.size > 2){
            hmap.set(s[left], hmap.get(s[left])-1);
            if (hmap.get(s[left]) === 0) hmap.delete(s[left]);
            left++;
        }
        res = Math.max(res, i-left+1);
    }
    return res;
};