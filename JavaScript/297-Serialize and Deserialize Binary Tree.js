/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    let data = [];
    let dfs = (root) =>{
        if (!root){
            data.push('#');
            return;
        }
        data.push(root.val.toString())
        dfs(root.left)
        dfs(root.right)
    }
    dfs(root);
    return data.join(" ");
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    data = data.split(" ");
    let dfs = () =>{
        if (data[0] === '#') return null;
        let root = new TreeNode(parseInt(data.shift()) )
        if (data[0]!=='#'){
            root.left = dfs()
        } else{
            data.shift()
        }
    
        if (data[0]!=='#'){
            root.right = dfs();
        } else{
            data.shift();
        }
        return root;
    }
    return dfs();
};