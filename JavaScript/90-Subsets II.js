/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    let res = new Array();
    nums.sort(function(a,b){return a-b;});
    
    let dfs = (start, val)=>{
        res.push(val);
        for (let i=start; i<nums.length; i++){
            if (i > start && nums[i] === nums[i-1]) continue;
            dfs(i+1, val.concat([nums[i]]));
        }
    }
    dfs(0, new Array());
    return res;
};