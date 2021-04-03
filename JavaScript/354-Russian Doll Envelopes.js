/**
 * @param {number[][]} envelopes
 * @return {number}
 */
var maxEnvelopes = function(envelopes) {
    envelopes.sort(function(a,b){
        if (a[0] === b[0]){
            return b[1] - a[1];
        }else{
            return a[0] - b[0];
        }
    })
    
    const N = envelopes.length;
    let dp = new Array();
    
    for (let i=0; i<N; i++){
        if (!dp.length || envelopes[i][1] > dp[dp.length-1]){
            dp.push(envelopes[i][1]);
        }else{
            let left = 0, right = dp.length-1;
            while (left + 1 < right){
                let mid = left + Math.floor((right-left)/2);
                if (envelopes[i][1] <= dp[mid]){
                    right = mid;
                }else{
                    left = mid;
                }
            }
            if (envelopes[i][1] <= dp[left]){
                dp[left] = envelopes[i][1];
            }else{
                dp[right] = envelopes[i][1];
            }
        }
    }
    return dp.length;
};