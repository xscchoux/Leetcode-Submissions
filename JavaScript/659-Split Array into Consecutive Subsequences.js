/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isPossible = function(nums) {
    let freq = new Map();
    for (let num of nums){
        freq.set(num, (freq.get(num)|| 0) + 1 )
    }
    
    let last = new Map();
    
    for (let num of nums){
        if (freq.get(num)){
            if (last.has(num-1) && last.get(num-1) !==0){
                last.set(num-1, last.get(num-1)-1);
                last.set(num, (last.get(num)||0)+1);
            }else if(freq.get(num+1) && freq.get(num+2)){
                freq.set(num+1, freq.get(num+1) - 1);
                freq.set(num+2, freq.get(num+2) - 1);
                last.set(num+2, (last.get(num+2)||0) + 1);
            }else{
                return false;
            }
            freq.set(num, freq.get(num)-1);
        }
    }
    return true;
};