/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} time
 * @param {number} change
 * @return {number}
 */
var secondMinimum = function(n, edges, time, change) {
    let graph = new Map();
    for (let i=1; i<=n; i++){
        graph.set(i, [])
    }
    for (let [u, v] of edges){
        graph.get(u).push(v);
        graph.get(v).push(u);
    }
    let freq = new Array(n+1).fill(0);
    let elapsed = new Array(n+1).fill(Number.POSITIVE_INFINITY);
    freq[0] = 1;
    let found = false;
    
    let queue = [[0, 1]]; // time cost, vertex 
    while (queue.length){
        let [currT, currV] = queue.shift();
        let quo = Math.floor(currT/change);
        if (quo%2){
            currT += 2*change - currT%(change*2);
        }
        for (let nxt of graph.get(currV)){
            if (currT + time !== elapsed[nxt] && freq[nxt] < 2){
                if (nxt === n){
                    if (!found) found = true;
                    else return currT+time;
                }     
                queue.push([currT+time, nxt]);
                freq[nxt]++;
                elapsed[nxt] = currT+time;
            }
        }
    }
};