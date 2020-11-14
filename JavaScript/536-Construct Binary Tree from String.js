/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {string} s
 * @return {TreeNode}
 */
var str2tree = function(s) {
    if (!s.length) return null;
    
    s = s.split("")
    
    function isCharNumber(c){
        return c >= '0' && c <= '9';
    }
    
    let dfs = () =>{
        if (s.length && (isCharNumber(s[0]) || s[0] === '-') ){
            var num = s.shift();
            while (s.length && isCharNumber(s[0])){
                num += s.shift();
            }
            var node = new TreeNode(parseInt(num,10));
        }

        if (s.length && s[0] === '('){
            s.shift();
            node.left = dfs();
        }
        
        if (s.length && s[0] === '('){
            s.shift();
            node.right = dfs()
        }
        
        if (s.length && s[0] === ')'){
            s.shift();
        }
        return node;
    }
    return dfs();    
};