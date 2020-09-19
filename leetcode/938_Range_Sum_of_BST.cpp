/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int ans=0;
    public void recur(TreeNode root , int l ,int r){
        if(root==null)return;
        if(root.val >=l && root.val<=r){
            ans+=root.val;
            recur(root.left,l,r);
            recur(root.right,l,r);
        }else if(root.val < l)recur(root.right,l,r);
         else if(root.val > r)recur(root.left,l,r);
    }
    public int rangeSumBST(TreeNode root, int L, int R) {
        recur(root,L,R);
        return ans;
    }
}