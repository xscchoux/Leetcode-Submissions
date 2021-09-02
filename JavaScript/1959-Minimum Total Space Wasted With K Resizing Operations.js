/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minSpaceWastedKResizing = function(nums, k) {
// Top-down DP
    
    const N = nums.length;
    let memo = Array(N).fill().map(() => Array(k+1).fill(-1));

    let dp = (start, k) =>{
        if (start === N) return 0;
        if (k<0) return Number.POSITIVE_INFINITY;
        if ( memo[start][k] !== -1) return memo[start][k]; 
        
        let total = 0, mx = 0, res = Number.POSITIVE_INFINITY;
        
        for (let j=start; j<N; j++){
            total += nums[j];
            mx = Math.max(nums[j], mx);
            res = Math.min(res, mx*(j-start+1)-total+dp(j+1, k-1) );
        }
        return memo[start][k] = res;
    }
    return dp(0, k);
};