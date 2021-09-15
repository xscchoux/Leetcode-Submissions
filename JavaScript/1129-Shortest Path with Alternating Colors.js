/**
 * @param {number} n
 * @param {number[][]} red_edges
 * @param {number[][]} blue_edges
 * @return {number[]}
 */
var shortestAlternatingPaths = function(n, red_edges, blue_edges) {
    let res = new Array(n).fill(-1);
    res[0] = 0;
    let graph = new Map();
    
    for (const [u, v] of red_edges){
        if (!graph.get(u)) graph.set(u, []);
        graph.get(u).push([v, 1]);
    }
    
    for (const [u, v] of blue_edges){
        if (!graph.get(u)) graph.set(u, []);
        graph.get(u).push([v, 0]);
    }
    
    let redVisited = new Array(n), blueVisited = new Array(n);
    
    let queue = [[0, 0, -1000]]; //node index, steps, color;
    
    while (queue.length){
        const size = queue.length;
        for (let i=0; i<size; i++){
            [currNode, step, color] = queue.shift();
            for (const [nxt, edgeColor] of graph.get(currNode)||[]){
                const arr = (edgeColor === 1)?redVisited:blueVisited
                if (edgeColor !== color && !arr[nxt]){
                    if (res[nxt] === -1) res[nxt] = step+1;
                    arr[nxt] = 1;
                    queue.push([nxt, step+1, edgeColor]);
                }
            }
        }
    }
    return res;
};