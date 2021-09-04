/**
 * @param {number[][]} trees
 * @return {number[][]}
 */
var outerTrees = function(trees) {
    const N = trees.length;
    if (N < 4) return trees;
    
    trees.sort(function(a,b){
        return a[0] === b[0] ? a[1]-b[1] : a[0] - b[0];
    })
    
    let isClockwise = (a, b, c) =>{
        return (c[0]-a[0])*(b[1]-a[1]) - (c[1]-a[1])*(b[0]-a[0]);
    }
    
    let upper = [];
    upperLen = 0;
    for (let i=0; i<N; i++){
        while (upperLen >= 2 && isClockwise(upper[upperLen-2], upper[upperLen-1], trees[i]) < 0){
            upper.pop();
            upperLen -= 1;
        }
        upper.push(trees[i]);
        upperLen += 1;
    }
    upper.pop();
    
    let lower = [];
    lowerLen = 0;
    for (let i=N-1; i>=0; i--){
        while (lowerLen >= 2 && isClockwise(lower[lowerLen-2], lower[lowerLen-1], trees[i]) < 0){
            lower.pop();
            lowerLen -= 1;
        }
        lower.push(trees[i]);
        lowerLen += 1;
    }
    lower.pop();
    
    return [...new Set(upper.concat(lower))]
};