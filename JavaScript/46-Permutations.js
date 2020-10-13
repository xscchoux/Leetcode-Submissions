/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let res = [];
    let used = new Array(nums.length).fill(false);
    
    let dfs = (val) =>{
        if (val.length === nums.length){
            res.push(val);
            return;
        }
        for (let i=0; i<nums.length; i++){
            if (used[i] === false){
                used[i] = true;
                dfs(val.concat(nums[i]))
                used[i] = false;
            }
        }
    }
    dfs([]);
    return res;
};