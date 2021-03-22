/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function(s) {
    let charArr = new Array(3).fill(0);
    let left = 0, res = 0;
    const N = s.length;
    
    for (let i=0; i<s.length; i++){
        charArr[s[i].charCodeAt(0) - 'a'.charCodeAt(0)] += 1;
        while(charArr.every(x => x > 0)){
            res += N-i;
            charArr[s[left].charCodeAt(0) - 'a'.charCodeAt(0)] -= 1;
            left += 1;
        }
    }
    return res;
};