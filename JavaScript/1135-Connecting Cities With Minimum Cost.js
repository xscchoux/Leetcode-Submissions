/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number}
 */

// Kruskal's algorithm
var minimumCost = function(n, connections) {
    let parent = new Map();
    for (let i=1; i<=n; i++){
        parent.set(i, i);
    }
    
    connections.sort(function(a,b){
        return a[2]-b[2];
    })
    
    let find = (x) =>{
        if (parent.get(x) === x){
            return x;
        }else{
            parent.set(x, find(parent.get(x)));
            return parent.get(x);
        }
    }
    
    count = 1;
    totCost = 0;
    
    for (let [u, v, cost] of connections){
        if (find(u) !== find(v)){
            count += 1;
            totCost += cost;
            if (count === n) return totCost;
            //union
            parent.set(parent.get(u), parent.get(v));
        }
    }
    
    return -1;
};