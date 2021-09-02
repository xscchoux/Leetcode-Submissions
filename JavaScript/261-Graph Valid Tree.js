/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {boolean}
 */
var validTree = function(n, edges) {
    
    if (edges.length !== n-1) return false;
    
    let parent = new Array(n).fill().map((_,i)=>i);
    
    let find = (node) =>{
        if (node === parent[node]){
            return node;
        }else{
            parent[node] = find(parent[node]);
            return parent[node];
        }
    }
    
    for (let [u, v] of edges){
        let parentU = find(u), parentV = find(v);
        if (parentU === parentV) return false;
        parent[parentU] = parentV;    
    }
    
    return true;
    
};