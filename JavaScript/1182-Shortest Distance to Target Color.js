/**
 * @param {number[]} colors
 * @param {number[][]} queries
 * @return {number[]}
 */
var shortestDistanceColor = function(colors, queries) {
    const N = colors.length;
    let leftmost = new Array(3).fill(N-1), rightmost = new Array(3).fill(0);
    let distance = new Array(3).fill().map(x=> new Array(N).fill(-1));
    
    for (let i=0; i<N; i++){
        let color = colors[i]-1;
        for (let j = rightmost[color]; j<=i; j++){
            distance[color][j] = i-j;
        }
        rightmost[color] = i;
    }
    
    for (let i=N-1; i>=0; i--){
        let color = colors[i]-1;
        for (let j = leftmost[color]; j>=i; j--){
            if (distance[color][j] === -1 || distance[color][j] > j-i){
                distance[color][j] = j-i;                
            }
        }
        leftmost[color] = i;
    }
    
    let res = [];
    for (let [ind, color] of queries){
        res.push(distance[color-1][ind]);    
    }
    
    return res;
};