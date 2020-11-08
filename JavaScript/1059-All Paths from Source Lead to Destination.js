/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} source
 * @param {number} destination
 * @return {boolean}
 */
var leadsToDestination = function(n, edges, source, destination) {
    let seen = new Set();
    let hmap = new Map();
    for (let edge of edges){
        if (!hmap.get(edge[0])){
            hmap.set(edge[0], new Array());
        }
        hmap.get(edge[0]).push(edge[1]);
    }
    
    let dfs = (node) => {
        if (node === destination && !hmap.get(node)){
            return true;
        } else if (node === destination || !hmap.get(node)){
            return false;
        }
        
        if (seen.has(node)){
            return false;
        }
        seen.add(node);
        let res = true;
        for (let nxt of hmap.get(node)){
            res = res&& dfs(nxt);
        }
        seen.delete(node);
        return res;
    }
    return dfs(source);
};