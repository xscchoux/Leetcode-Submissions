/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
// sliding window
var maxScore = function(cardPoints, k) {
    let N = cardPoints.length;
    
    // Need to set an initial value in the reduce function 
    // An error occurs when cardPoints.slice(0,N-k) is an empty array
    
    let sums = cardPoints.slice(0,N-k).reduce(function(a,b){
        return a+b;
    },0);
    let res = sums;
    for (let i=N-k; i<N; i++){
        sums = sums + cardPoints[i] - cardPoints[i-N+k];
        res = Math.min(res, sums);
    }
    
    return cardPoints.reduce((a,b)=>a+b) - res;
};