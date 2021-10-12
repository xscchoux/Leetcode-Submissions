/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minimumXORSum = function(nums1, nums2) {
// DP
    const N = nums1.length;
    let memo = new Map();
    
    let dfs = (idx, bitmask) =>{
        if (bitmask === 0){
            return 0;
        }
        if (memo.has(`${idx}-${bitmask}`)){
            return memo.get(`${idx}-${bitmask}`);
        }
        
        let res = Number.POSITIVE_INFINITY;
        for (let i=0; i<N; i++){
            if (  (bitmask>>i)&1 ){
                res = Math.min(res, (nums1[idx]^nums2[i])+dfs(idx+1, bitmask^(1<<i)))
            }
        }
        memo.set(`${idx}-${bitmask}`, res);
        return res;
    }
    
    return dfs(0, (1<<N)-1);
};