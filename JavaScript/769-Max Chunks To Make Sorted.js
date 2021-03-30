/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
    let mx = 0, res = 0;
    for (let [idx, val] of arr.entries()){
        mx = Math.max(val, mx);
        if (idx === mx){
            res++;
        }
    }
    return res;
};