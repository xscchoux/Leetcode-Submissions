/**
 * @param {number[][]} intervals
 * @return {number}
 */

// sweep line, O(NlogN)
var minMeetingRooms = function(intervals) {
    let arr = [];
    for (let interval of intervals){
        arr.push([interval[0], 1]);
        arr.push([interval[1], -1]);
    }
    arr.sort(function(a,b){
        if (a[0]===b[0]) return a[1]-b[1];
        else return a[0]-b[0];
    })
    let count = 0
    let res = 0
    for (let i=0; i<arr.length; i++){
        count += arr[i][1];
        res = Math.max(res, count);
    }
    return res;
};