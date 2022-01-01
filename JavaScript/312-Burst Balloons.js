/**
 * @param {number[]} nums
 * @return {number}
 */
var maxCoins = function(nums) {
    const length = nums.length;
    nums.unshift(1);
    nums.push(1);
    let dp = new Array(length+2).fill().map(()=>new Array(length+2).fill(0));
    
    for (let l=1; l<=length; l++){
        for (let i=1; i<length+1; i++){
            let j = i+l-1;
            if (j > length ) break;
            for (let k=i; k<=j; k++){
                dp[i][j] = Math.max(dp[i][j], dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j]);
            }
        }
    }
    return dp[1][length];
};