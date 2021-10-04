/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var waysToPartition = function(nums, k) {
    let res = 0, prefixSum = 0;
    const total = nums.reduce((acc,x)=>acc+x), n = nums.length;
    let diff = new Array();
    
    for (let i=0; i<n-1; i++){
        prefixSum += nums[i];
        if (prefixSum - (total-prefixSum) === 0){
            res += 1;
        }
        diff.push(prefixSum - (total-prefixSum));
    }
    
    let left = new Map(), right = new Map();
    for (let x of diff){
        right.set(x, (right.get(x)||0)+1 );
    }

    for (let i=0; i<n-1; i++){
        let change = k - nums[i];
        res = Math.max(res, (left.get(change)||0) + (right.get(-change)||0) );
        left.set(diff[i], (left.get(diff[i])||0)+1 );
        right.set(diff[i], right.get(diff[i])-1 );
    }
    
    let lastChange = k - nums[n-1];
    res = Math.max(res, left.get(lastChange)||0);
    
    return res;
};