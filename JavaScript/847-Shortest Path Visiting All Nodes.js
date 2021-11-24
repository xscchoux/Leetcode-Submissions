/**
 * @param {number[][]} graph
 * @return {number}
 */
var shortestPathLength = function(graph) {
    const N = graph.length;
    const target = (1<<N)-1;
    let queue = new Array();
    let visited = new Array(N);
    for (let i=0; i<N; i++){
        visited[i] = new Set([1<<i]);
        queue.push([i, 1<<i]);
    }
    
    let step = 0;
    
    while (queue.length){
        const size = queue.length;
        for (let i=0; i<size; i++){
            [node, state] = queue.shift();
            if (state === target) return step;
            for (let nxt of graph[node]){
                if (!visited[nxt].has(state|(1<<nxt))){
                    visited[nxt].add(state|(1<<nxt));
                    queue.push([nxt, state|(1<<nxt)]);
                }
            }
        }
        step += 1;
    }
};