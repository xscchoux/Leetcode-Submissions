/**
 * @param {number[]} time
 * @return {number}
 */
var numPairsDivisibleBy60 = function(time) {
    
    let count = 0;
    let hmap = new Map();

    for (let t of time){
        let pair = 60 - t%60;
        if (pair === 60){
            pair = 0;
        }
        count += hmap.get(pair) || 0;
        hmap.set(t%60, (hmap.get(t%60)||0)+1);
    }
    return count;
};