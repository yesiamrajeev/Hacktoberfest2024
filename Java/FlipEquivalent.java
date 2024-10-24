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
class FlipEquivalent {
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        Queue<TreeNode> q1 = new LinkedList<>(), q2 = new LinkedList<>();
        q1.offer(root1);
        q2.offer(root2);
        while (!q1.isEmpty() && !q2.isEmpty()) {
            TreeNode n1 = q1.poll(), n2 = q2.poll();
            if (n1 == null || n2 == null) {
                if (n1 != n2) return false;
                else continue;
            }
            if (n1.val != n2.val) {
                return false;
            }
            if (n1.left == n2.left || n1.left != null && n2.left != null && n1.left.val == n2.left.val) {
                q1.addAll(Arrays.asList(n1.left, n1.right));
            }else {
                q1.addAll(Arrays.asList(n1.right, n1.left));
            }
            q2.addAll(Arrays.asList(n2.left, n2.right));
        }
        return q1.isEmpty() && q2.isEmpty();
    }
}
