/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var isPossibleDivide = function(nums, k) {
    let freq = new Map();
    for (let num of nums){
        freq.set(num, (freq.get(num)||0) + 1 );
    }
    let keys = [...freq.keys()].sort((a,b)=>a-b);
    
    for (let key of keys){
        if (freq.get(key) > 0){
            for (let m = key + k -1; m > key; m--){
                if (freq.get(m) >= freq.get(key)){
                    freq.set(m, freq.get(m) - freq.get(key))
                }else{
                    return false;
                }
            }
            freq.set(key, 0);
        }
    }
    return true;
};