/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function(nums) {
    const N = nums.length;
    if (N <= 1) return 0;
    let mx = nums[0], mn = nums[0]
    
    for (let i=0; i<nums.length; i++){
        mx = Math.max(mx, nums[i]);
        mn = Math.min(mn, nums[i]);
    }
    
    const bucketSize = Math.max(1, Math.floor((mx-mn)/(N-1)) );
    const nb_bucket = Math.floor( (mx-mn)/bucketSize ) + 1;

    let bucket = new Array(nb_bucket).fill(null);
    
    for (let num of nums){
        const idx = Math.floor( (num-mn)/bucketSize );
        if (bucket[idx] === null){
            bucket[idx] = [num, num];
        }else{
            bucket[idx][0] = Math.max(bucket[idx][0], num);
            bucket[idx][1] = Math.min(bucket[idx][1], num);
        }
    }
    
    let prev = 0, res = 0;
    for (let i=1; i<bucket.length; i++){
        if (bucket[i] === null) continue;
        res = Math.max(res, bucket[i][1] - bucket[prev][0]);
        prev = i;
    }
    
    return res;
};