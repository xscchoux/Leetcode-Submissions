/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number}
 */
var minMoves = function(nums, limit) {
    let N = nums.length;
    let diffMap = new Map();
    
    for (let i=0; i<N/2; i++){
        let a = nums[i];
        let b = nums[N-1-i];
        diffMap.set(a+b, (diffMap.get(a+b)||0) - 1 );
        diffMap.set(a+b+1, (diffMap.get(a+b+1)||0) + 1 );
        let min = Math.min(a,b), max = Math.max(a,b);
        diffMap.set(min+1, (diffMap.get(min+1)||0) - 1 );
        diffMap.set(max+limit+1, (diffMap.get(max+limit+1)||0) + 1);
    }
    
    let res = N;
    let cur = N;
    for (let i=2; i<= 2*limit+1; i++){
        cur += diffMap.get(i) || 0;
        res = Math.min(res, cur);
    }
    return res;
};