/**
 * @param {string} s
 * @return {number}
 */
var longestPalindromeSubseq = function(s) {
    let res = 0;
    const n = s.length;
    const memo = new Array(n).fill().map(x=> new Array(n).fill());
    
    let dp = (i, j) =>{
        if (memo[i][j] !== undefined){
            return memo[i][j];
        }
        let ans = 0;
        for (let start=i+1; start<=j-2; start++){
            for (let end=j-1; end > start; end--){
                if (s[start] === s[end] && s[start] !== s[i]){
                    ans = Math.max(ans, 2+dp(start, end));
                    break;
                }
            }
        }
        memo[i][j] = ans;
        return ans;
    }
    
    for (let i=0; i<n-1; i++){
        for (let j=n-1; j>i; j--){
            if (s[i] === s[j]){
                res = Math.max(res, 2+dp(i, j));
                break;
            }
        }
    }
    return res;
};