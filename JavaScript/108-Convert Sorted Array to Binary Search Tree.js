/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    let dfs = (left, right)=>{
        if (left > right) return null;
        if (left === right) return new TreeNode(nums[left]);
        const mid = left + Math.floor((right-left)/2);
        const currNode = new TreeNode(nums[mid]);
        currNode.left = dfs(left, mid-1);
        currNode.right = dfs(mid+1, right);
        return currNode;
    }
    return dfs(0, nums.length-1);
};