/**
 * // Definition for a Node.
 * function Node(val, children) {
 *    this.val = val === undefined ? 0 : val;
 *    this.children = children === undefined ? [] : children;
 * };
 */

/**
 * @param {Node} root
 * @return {number}
 */
var diameter = function(root) {
    let res = 0;
    
    let dfs = (root) =>{
        if (!root.children.length){
            return 0;
        }
        let [firstmax, secondmax] = [0, 0];
        for (let nxt of root.children){
            let value = dfs(nxt);
            if (value + 1 > firstmax){
                secondmax = firstmax
                firstmax = value + 1;
            } else if (value + 1 > secondmax){
                secondmax = value + 1;
            }
        }
        res = Math.max(res, firstmax + secondmax);
        return firstmax;
    }
    dfs(root);
    return res;
};