/**
 * @param {number} n
 * @param {number[][]} edgeList
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var distanceLimitedPathsExist = function(n, edgeList, queries) {
    
    let parent = new Array(n).fill().map((_,i)=>i);
    let queryIdx = new Array(queries.length).fill().map((_,i)=>i);
    let rank = new Array(n).fill(1);
    
    let find = (x) =>{
        let path = new Array();
        while (x!=parent[x]){
            path.push(x);
            x = parent[x];
        }
        for (let xx of path){
            parent[xx] = x;
        }
        return x;
    }
    
    let union = (x, y)=>{
        let px = find(x), py = find(y);
        if (px === py) return;
        
        if (rank[px] < rank[py]){
            parent[px] = py;
        }else if (rank[px] > rank[py]){
            parent[py] = px;
        }else{
            parent[px] = py;
            rank[py] += 1;
        }
    }
    
    edgeList.sort(function(a,b){
        return a[2]-b[2];
    })
    
    queryIdx.sort(function(a,b){
        return queries[a][2] - queries[b][2];
    })

    let edgeIdx = 0;
    let res = new Array(queries.length).fill(false);
    
    for (let index of queryIdx){
        let [start, end, limit] = queries[index]
        while (edgeIdx < edgeList.length && edgeList[edgeIdx][2] < limit){
            union(edgeList[edgeIdx][0], edgeList[edgeIdx][1]);
            edgeIdx++;
        }
        if (find(start) === find(end)){
            res[index] = true;
        }
    }
    return res;
};