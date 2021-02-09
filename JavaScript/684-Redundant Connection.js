/**
 * @param {number[][]} edges
 * @return {number[]}
 */
var findRedundantConnection = function(edges) {
    const parents = new Map();
    const n = edges.length;
    
    for (let i=1; i<=n; i++){
        parents.set(i, i);
    }
    
    let find = (node) =>{
        let path = [];
        while (node !== parents.get(node)){
            path.push(node);
            node = parents.get(node);
        }
        for (let n of path){
            parents.set(n, node);
        }
        return node;
    }
    
    for (let edge of edges){
        let parent1 = find(edge[0]), parent2 = find(edge[1]);
        if (parent1 === parent2){
            return edge;
        }
        parents.set(parent2, parent1);   // union
    }
};