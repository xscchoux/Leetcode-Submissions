/**
 * @param {string} s
 * @return {number}
 */

// Time complexity: O(n^2)
// Space complexity: O(n^2)

var minCut = function(s) {
    const n = s.length;
    const dp = new Array(n);
    for (let i=0; i<n; i++){
        dp[i]=i;
    }
    const isPalindrome = new Array(n).fill(0).map(x=>new Array(n).fill(false));
    
    for (let end=0; end<n; end++){
        for (let start=0; start<=end; start++){
            if (s[start] === s[end] && (end-start<=1 || isPalindrome[start+1][end-1])){
                isPalindrome[start][end] = true;
                if (start === 0){
                    dp[end] = 0;
                    continue;
                }
                dp[end] = Math.min(dp[end], dp[start-1]+1);
            }
        }
    }
    return dp[n-1];
};