/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countComponents = function(n, edges) {
    let graph = new Map();
    let visited = new Array(n).fill(false);
    
    for (let i=0; i<n; i++){
        graph.set(i, []);
    }
    
    for (let [u,v] of edges){
        graph.set(u, graph.get(u).concat([v]) );
        graph.set(v, graph.get(v).concat([u]) );
    }
    
    let dfs = (start) =>{
        for (let nxt of graph.get(start)){
            if (!visited[nxt]){
                visited[nxt] = true;
                dfs(nxt);
            }
        }
    }
    
    let count = 0;
    
    for (let i=0; i<n; i++){
        if(!visited[i]){
            count++;
            dfs(i);
        }
    }
    
    return count;
};