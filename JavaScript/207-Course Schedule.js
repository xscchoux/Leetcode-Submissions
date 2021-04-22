/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
    let indegree = new Array(numCourses).fill(0);    
    let graph = new Map();
    
    for (let [a, b] of prerequisites){
        graph.set(b, (graph.get(b) || []).concat([a]));
        indegree[a] += 1;
    }
    
    let queue = new Array();
    for (let i=0; i<numCourses; i++){
        if (indegree[i] === 0) queue.push(i);
    }
    
    while (queue.length){
        let size = queue.length;
        // console.log(queue)
        for (let j=0; j<queue.length; j++){
            let curr = queue.shift();
            if (graph.get(curr)){
                for (let nxt of graph.get(curr)){
                    indegree[nxt] -= 1;
                    if (indegree[nxt] === 0){
                        queue.push(nxt);
                    }
                }
                graph.delete(curr);
            }
        }
    }
    
    if (graph.size === 0){
        return true;
    }else{
        return false;
    }
};