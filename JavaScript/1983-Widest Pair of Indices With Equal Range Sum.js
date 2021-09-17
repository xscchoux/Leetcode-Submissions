/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var widestPairOfIndices = function(nums1, nums2) {
    let prefixAll = [0];
    const N = nums1.length
    for (let i=0; i<N; i++){
        prefixAll.push(nums1[i]-nums2[i]+prefixAll[prefixAll.length-1]);
    }
    
    let res = 0, hmap = new Map();
    for (let i=0; i<N+1; i++){
        if ( !hmap.has(prefixAll[i]) ){
            hmap.set(prefixAll[i], i);
        }else{
            res = Math.max(res, i-hmap.get(prefixAll[i]) );
        }
    }
    return res;
};