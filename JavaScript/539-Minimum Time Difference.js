/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {
    let time = [];
    for (let timePoint of timePoints){
        time.push(60*parseInt(timePoint.substr(0,2)) + parseInt(timePoint.substr(3,5)));
    }
    
    time.sort(function(a,b){
        return a-b;
    });
    
    let res = 1440;
    for (let i=1; i<time.length; i++){
        res = Math.min(res, time[i] - time[i-1]);
    }
    
    res = Math.min(res, 1440 - (time[time.length-1] - time[0]) );
    
    return res;
};