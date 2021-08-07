/**
 * @param {number[][]} intervals
 * @return {number[]}
 */
var findRightInterval = function(intervals) {
    let startList = new Array();
    for (let i=0; i<intervals.length; i++){
        startList.push([intervals[i][0], i]);
    }
    startList.sort(function(a, b){
        return a[0] - b[0];
    })
    
    let bs = (target) =>{
        let left = 0, right = startList.length-1;
        while (left + 1 < right){
            let mid = left + ((right-left)>>1);
            if (startList[mid][0] >= target){
                right = mid;
            }else{
                left = mid;
            }
        }
        if (startList[left][0] >= target){
            return left;
        }else if(startList[right][0] >= target){
            return right;
        }else{
            return -1;
        }
    }
    
    let res = new Array();
    for (let interval of intervals){
        let pos = bs(interval[1]);
        if (pos === -1){
            res.push(-1);
        }else{
            res.push(startList[pos][1]);
        }    
    }
    
    return res;
};