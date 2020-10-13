/**
 * @param {number[][]} graph
 * @return {number[][]}
 */
var allPathsSourceTarget = function(graph) {
    let dag = new Map();
    let res = [];
    
    for (let i=0; i<graph.length; i++){
        dag[i] = graph[i]
    }
    
    let dfs = (start, path) =>{
        if (start === graph.length-1){
            res.push(path);
            return
        }
        for (let nxt of dag[start]){
            dfs(nxt, path.concat([nxt]));
        }
    }
    
    dfs(0, [0]);
    return res;
};