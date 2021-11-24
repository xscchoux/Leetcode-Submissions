/**
 * @param {number[][]} firstList
 * @param {number[][]} secondList
 * @return {number[][]}
 */
var intervalIntersection = function(firstList, secondList) {
    let idx1 = 0, idx2 = 0;
    let res = new Array();
    while (idx1 < firstList.length && idx2 < secondList.length){
        let lo = Math.max(firstList[idx1][0], secondList[idx2][0]);
        let hi = Math.min(firstList[idx1][1], secondList[idx2][1]);
        if (lo <= hi) res.push([lo, hi]);
        if (firstList[idx1][1] <= secondList[idx2][1]){
            idx1 += 1;
        }else{
            idx2 += 1;
        }
    }
    return res;
};