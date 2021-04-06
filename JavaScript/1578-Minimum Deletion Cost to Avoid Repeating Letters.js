/**
 * @param {string} s
 * @param {number[]} cost
 * @return {number}
 */
var minCost = function(s, cost) {
    let res = 0, prevLargeCost = cost[0];
    
    for (let i=1; i<=s.length-1; i++){
        if (s[i] === s[i-1]){
            if (cost[i] > prevLargeCost){
                res += prevLargeCost;
                prevLargeCost = cost[i];
            }else{
                res += cost[i];
            }
        }else{
            prevLargeCost = cost[i];
        }
    }
    return res;
};