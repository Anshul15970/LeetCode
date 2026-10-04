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
    public List<Integer> largestValues(TreeNode root) {
        if(root == null){return new ArrayList<>();}
        ArrayList<Integer> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            int n = q.size();
            int a = Integer.MIN_VALUE;
            for(int i = 0;i<n;i++){
                TreeNode node = q.poll();
                a = Math.max(node.val,a);
                if(node.left != null){q.offer(node.left);}
                if(node.right != null){q.offer(node.right);}
            }
            ans.add(a);
        }
        return ans;
    }
}