/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function(nums) {
    const N = nums.length;
    let hmaps = new Array(), count = 0;
    
    for (let i=0; i<N; i++){
        hmaps.push(new Map());
    }
    
    for (let i=0; i<N; i++){
        for (let j=0; j<i; j++){
            let diff = nums[i] - nums[j];
            if (hmaps[j].has(diff)){
                count += hmaps[j].get(diff);
                hmaps[i].set(diff, (hmaps[i].get(diff)|| 0) + hmaps[j].get(diff) + 1 );
            }else{
                hmaps[i].set(diff, (hmaps[i].get(diff) || 0) + 1  );
            }
        }
    }
    return count;
    
};