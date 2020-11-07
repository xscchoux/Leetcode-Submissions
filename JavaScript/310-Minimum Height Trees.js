/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    if (edges.length === 0){
        return [0];
    }
    
    let graph = new Map();
    for (let i=0; i<n; i++){
        graph[i] = new Set();
    }
    
    for (let [e1, e2] of edges){
        graph[e1].add(e2);
        graph[e2].add(e1);
    }

    let leaves = [];
    
    for (let i=0; i<n; i++){
        if (graph[i].size == 1){
            leaves.push(i);
        }
    }
    
    while (n>2){
        let leaveNum = leaves.length;
        n -= leaveNum
        for (let i=0; i<leaveNum; i++){
            let l = leaves.shift();
            for (let parent of graph[l]){
                graph[parent].delete(l);
                if (graph[parent].size === 1){
                    leaves.push(parent);
                }
            }
        }
    }
    return leaves;
};