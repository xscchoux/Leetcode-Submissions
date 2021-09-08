/**
 * @param {number[]} houses
 * @param {number} k
 * @return {number}
 */
var minDistance = function(houses, k) {
    const N = houses.length, max = Number.POSITIVE_INFINITY;
    if (k >= N) return 0;
    
    houses.sort(function(a,b){return a-b;})
    let memo = new Array(N);
    
    for(let i = 0; i < N; i++){
        memo[i] = new Array(N);
        for(let j = 0; j < N; j++){
            memo[i][j] = new Array(k + 1).fill(max);
        }
    }
    
    let dfs = (start, end, boxes) =>{ 
        if (boxes > end-start+1) return max;
        
        if (boxes === end-start+1) return 0;
        
        if (memo[start][end][boxes] !== max){
            return memo[start][end][boxes];
        }
        
        if (boxes === 1){
            let median = (start+end)>>1;
            let ans = 0;
            for (let i=start; i<=end; i++){
                ans += Math.abs(houses[i]-houses[median]);
            }
            memo[start][end][boxes] = ans;
            return ans;
        }
        
        let res = max;
        for (let x=start; x<=end; x++){
            res = Math.min(res, dfs(start, x, 1) + dfs(x+1, end, boxes-1) );
        }
        
        memo[start][end][boxes] = res;
        return res;
    }
    return dfs(0, N-1, k);
};