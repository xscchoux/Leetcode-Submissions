/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var sumOfDistancesInTree = function(n, edges) {
    let count = new Array(n).fill(0), subRes = new Array(n).fill(0);
    
    let graph = new Map();
    for (let [start, end] of edges){
        graph.set(start, (graph.get(start) || new Array()).concat([end]) );
        graph.set(end, (graph.get(end) || new Array()).concat([start]) );
    }
    
    let dfs = (curr, prev) =>{
        for (let nxt of graph.get(curr)||[] ){
            if (nxt === prev) continue;
            dfs(nxt, curr);
            subRes[curr] += (count[nxt] + subRes[nxt]);
            count[curr] += count[nxt];
        }
        count[curr] += 1;
    }
    
    let dfs2 = (curr, prev) =>{
        for (let nxt of graph.get(curr)||[] ){
            if (nxt === prev) continue;
            subRes[nxt] += (n-count[nxt]) + (subRes[curr] - subRes[nxt] - count[nxt]);
            dfs2(nxt, curr);
        }
    }
    
    dfs(0, null);
    dfs2(0, null);
    return subRes;
};