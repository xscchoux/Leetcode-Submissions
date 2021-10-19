/**
 * @param {string} word
 * @return {number}
 */
var wonderfulSubstrings = function(word) {
    let dp = new Array(1025).fill(0);
    dp[0] = 1;
    let prev = 0, res = 0;
    
    for (let s of word){
        let curr = (1<<(s.charCodeAt(0) - "a".charCodeAt(0)))^prev;
        res += dp[curr];
        for (let i=0; i<10; i++){
            res += dp[curr^(1<<i)];
        }
        dp[curr] += 1;
        prev = curr;
    }
    return res;
};