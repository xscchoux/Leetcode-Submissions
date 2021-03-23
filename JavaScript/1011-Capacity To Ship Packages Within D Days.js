/**
 * @param {number[]} weights
 * @param {number} D
 * @return {number}
 */
var shipWithinDays = function(weights, D) {
    let left = Math.max(...weights), right = weights.reduce(function(acc,x){return acc+x;});
    
    let countDay = (capacity) =>{
        let days = 0, tot = 0;
        for (idx = 0; idx < weights.length; idx++){
            if (tot + weights[idx] > capacity){
                tot = weights[idx];
                days += 1;
            }else{
                tot += weights[idx];
            }
        }
        return days+1;
    }
    
    while (left + 1 < right){
        let mid = left + Math.floor((right-left)/2);
        if (countDay(mid) <= D){
            right = mid;
        }else{
            left = mid;
        }
    }
    if (countDay(left) <= D){
        return left;
    }else{
        return right;
    }
};