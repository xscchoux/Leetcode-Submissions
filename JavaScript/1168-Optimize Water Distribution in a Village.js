/**
 * @param {number} n
 * @param {number[]} wells
 * @param {number[][]} pipes
 * @return {number}
 */
var minCostToSupplyWater = function(n, wells, pipes) {
    let parent = new Map();
    for (let i=0; i<=n; i++){
        parent.set(i, i);
    }
    let find = (index)=>{
        let path = new Array();
        while (parent.get(index) !== index){
            path.push(index);
            index = parent.get(index);
        }
        for (let xx of path){
            parent.set(xx, index);
        }
        return index
    }
    let union = (a, b)=>{
        let parentA = find(a), parentB = find(b);
        if (parentA === parentB){
            return false;
        }else{
            parent.set(parentB, parentA);
            return true;
        }
    }
    let res = 0;
    
    for (let i=0; i<wells.length; i++){
        pipes.push([0,i+1,wells[i]]);
    }
    pipes.sort(function(a, b){
        return a[2] - b[2];
    })
    
    for (let pipe of pipes){
        if (union(pipe[0], pipe[1])){
            res += pipe[2]
        }
    }
    return res;
};