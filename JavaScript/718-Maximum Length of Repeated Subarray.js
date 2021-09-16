/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findLength = function(nums1, nums2) {
    const n1 = nums1.length, n2 = nums2.length;
    let res = 0;
    let dp = new Array(n2+1).fill().map(()=>new Array(n1+1).fill(0));
    
    for (let r=1; r<=n2; r++){
        for (let c=1; c<=n1; c++){
            if (nums1[c-1] === nums2[r-1]){
                dp[r][c] = dp[r-1][c-1]+1;
                res = Math.max(dp[r][c], res);
            }
        }
    }
    return res;
};