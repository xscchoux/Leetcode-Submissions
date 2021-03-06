/**
 * @param {number[]} A
 * @param {number} S
 * @return {number}
 */
var numSubarraysWithSum = function(A, S) {
    let preSum = new Map();
    preSum.set(0, 1);
    let total = 0, res = 0;
    
    for (let num of A){
        total += num;
        if (preSum.has(total-S)){
            res += preSum.get(total-S);
        }
        preSum.set(total, (preSum.get(total) || 0) + 1 );
    }
    return res;
};