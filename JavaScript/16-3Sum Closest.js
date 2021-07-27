/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    nums.sort(function(a,b){
        return a-b;
    });
    const N = nums.length;
    
    let tmp = Number.POSITIVE_INFINITY, res = 0;
    for (let i=0; i<N-2; i++){
        let j = i+1, k = N-1;
        while (j < k){
            let sum = nums[i] + nums[j] + nums[k];
            let diff = sum - target;
            if (diff === 0) return sum;
            if (Math.abs(diff) < tmp){
                tmp = Math.abs(diff);
                res = sum;
            }
            if (diff > 0) k--;
            else j++;
        }
    }
    return res;
};
