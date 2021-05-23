/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    let total = 0, curr = 0, startIdx = 0;
    
    for (let i=0; i<gas.length; i++){
        total += gas[i] - cost[i];
        curr += gas[i] - cost[i];
        if (curr < 0){
            curr = 0;
            startIdx = i+1;
        }
    }
    
    return (total < 0) ? -1: startIdx;
};