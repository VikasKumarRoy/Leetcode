// Problem - 623

// https://leetcode.com/problems/add-one-row-to-tree/

// O(n) time complexity and O(n) space solution

class Solution {
    public TreeNode util(TreeNode root, int v, int d, int dir) {
        if(d == 1) {
            TreeNode node = new TreeNode(v);
            if(dir == 1) {
                node.right = root;
                node.left = null;
            }
            else {
                node.left = root;
                node.right = null;
            }
            return node;
        }
        if(root == null)
            return root;
        root.left = util(root.left, v, d-1, 0);
        root.right = util(root.right, v, d-1, 1);
        return root;
    }
    
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if(d == 1) {
            TreeNode node = new TreeNode(v);
            node.left = root;
            return node;
        }
        root.left = util(root.left, v, d-1, 0);
        root.right = util(root.right, v, d-1, 1);
        return root;
    }
}
