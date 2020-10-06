/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let res = [];
    candidates.sort(function(a,b){return a-b;})

    let dfs = (remain, val, start) => {
        if (remain === 0) res.push(val);
        for (let i=start; i< candidates.length; i++){
            if (candidates[i]>remain) break;
            dfs(remain-candidates[i], val.concat([candidates[i]]), i)
        }
    }
    
    dfs(target, [], 0);
    return res;
};