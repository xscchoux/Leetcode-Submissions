/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode pre = new TreeNode(Integer.MIN_VALUE);
    TreeNode first;
    TreeNode second;
    public void inorder(TreeNode root){
        if (root == null) return;
        inorder(root.left);
        if (root.val < pre.val){
            if (first == null) first = pre;
            if (first != null) second = root;
        }
        pre = root;
        inorder(root.right);
    }
    
    
    public void recoverTree(TreeNode root) {
        inorder(root);
        int tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }
}