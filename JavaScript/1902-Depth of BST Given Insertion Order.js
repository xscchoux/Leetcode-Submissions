/**
 * @param {number[]} order
 * @return {number}
 */
var maxDepthBST = function(order) {
    const N = order.length;
    
    if (Math.max(...order) === order[0] && Math.min(...order) === order[N - 1] || Math.min(...order) == order[0] && Math.max(...order) === order[N - 1]){
        return N;
    }
    
    let dfs = (arr) =>{
        if (!arr.length) return 0;
        let curr = arr[0], left = new Array(), right = new Array();
        for (let x of arr){
            if (x < curr){
                left.push(x);
            }else if (x > curr){
                right.push(x);
            }
        }
        return 1+Math.max(dfs(left), dfs(right));
    }
    
    return dfs(order);
};