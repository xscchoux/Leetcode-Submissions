/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var numSubseq = function(nums, target) {
    
    const kMod = 1000000007;
    const n = nums.length;
    let j = n-1, res = 0;
    
    nums.sort(function(a,b){return a-b});
    
    let calPow = new Array(n);
    calPow[0] = 1
    for (let i=1; i<n; i++){
        calPow[i] = calPow[i-1]*2%kMod;
    }
    
    
    for (let i=0; i<n; i++){
        if (nums[i]*2 > target) break;
        while (nums[i] + nums[j] > target){
            j--;
        }
        res += calPow[j-i];
    }
    return res%kMod;
};