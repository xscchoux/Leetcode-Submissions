/**
 * @param {number[]} nums
 * @return {number}
 */
var deleteAndEarn = function(nums) {
    let hmap = new Map();
    let skip = 0, using = 0, prev = null;
    for (let num of nums){
        hmap.set(num, (hmap.get(num)||0) + 1);
    }
    sortedNum = [...hmap.keys()].sort(function(a,b){
        return a-b;
    })
    
    for (let num of sortedNum){
        if (num-1 !== prev){
            [skip, using] = [Math.max(skip, using), Math.max(skip, using) + num*hmap.get(num)];
        }else{
            [skip, using] = [Math.max(skip, using), skip + num*hmap.get(num)];
        }
        prev = num;
    }
    return Math.max(skip, using);
};