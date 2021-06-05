/**
 * @param {number[][]} intervals
 * @return {number}
 */
var eraseOverlapIntervals = function(intervals) {
    intervals.sort(function(a,b){return a[1]-b[1]});
    
    let prev = Number.NEGATIVE_INFINITY, count=0;
    for (let interval of intervals){
        if (interval[0] >= prev){
            prev = interval[1];
        }else{
            count += 1;
        }
    }
    return count;
};