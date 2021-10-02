/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var canPartitionKSubsets = function(nums, k) {
    let tot = nums.reduce((a,b)=>a+b,0);
    
    if (tot%k) return false;
    
    const subSum = Math.floor(tot/k);
    nums.sort(function(a,b){return b-a;});
    let arr = new Array(k).fill(0);
    
    let dfs = (idx) =>{
        if (idx === nums.length){
            return true;
        }
        for (let i=0; i<k; i++){
            if (nums[idx] + arr[i] <= subSum){
                arr[i] += nums[idx];
                if (dfs(idx+1)) return true;
                arr[i] -= nums[idx];
            }
            if (arr[i] === 0) break;
        }
        return false;
    }
    return dfs(0);
};