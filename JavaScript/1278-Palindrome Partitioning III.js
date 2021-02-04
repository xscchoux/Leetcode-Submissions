/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var palindromePartition = function(s, k) {
    const n = s.length;
    
    let changeCount = (left, right) =>{
        let count = 0;
        while (left < right){
            if (s[left] !== s[right]){
                count++;
            }
            left++;
            right--;
        }
        return count;
    }
    
    const memo = new Array(n).fill().map(a => new Array(k + 1))
    
    let dfs = (start, kLeft)=>{
        if (memo[start][kLeft] !== undefined){
            return memo[start][kLeft];
        }
        if (n-start === kLeft){
            return 0;
        }
        if (kLeft === 1){
            return changeCount(start, n-1);
        }
        let minimumChange = Number.POSITIVE_INFINITY;
        for (let split = start; split <= n-kLeft; split++){
            minimumChange = Math.min(minimumChange, changeCount(start, split) + dfs(split+1, kLeft-1));
        }
        memo[start][kLeft] = minimumChange;
        return minimumChange;
    }
    return dfs(0, k)
};