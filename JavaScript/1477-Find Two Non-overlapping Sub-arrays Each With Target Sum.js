/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var minSumOfLengths = function(arr, target) {
// sliding window + DP
    const N = arr.length;
    let dp = new Array(N).fill(Number.POSITIVE_INFINITY);
    let tot = 0;
    let minLen = Number.POSITIVE_INFINITY;
    let start = 0;
    let res = Number.POSITIVE_INFINITY;
    
    for (let i=0; i<N; i++){
        tot += arr[i];
        while (tot > target){
            tot -= arr[start];
            start++;
        }
        if (tot === target){
            let length = i - start + 1;
            if (start > 0 && dp[start-1] !== Number.POSITIVE_INFINITY){
                res = Math.min(res, length + dp[start-1]);
            }
            minLen = Math.min(minLen, length);
        }
        dp[i] = minLen;
    }
    if (res === Number.POSITIVE_INFINITY) return -1;
    else return res;
};