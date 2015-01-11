package org.speedfirst.leetcode.not_in_oj.tree;

import org.speedfirst.leetcode.basic.TreeNode;

/**
 * Find whether a binary tree B is a subTree of binary tree A.
 * Assuming A is always larger than B.
 *
 * @author jiankuan
 * @since 1/11/15
 */
public class FindTreeInTree {

    public boolean isSubTree(TreeNode rootA, TreeNode rootB) {
        if (rootA == null || rootB == null) return false;

        if (rootA.val == rootB.val) {
            boolean matched = isMatch(rootA, rootB);
            if (matched) {
                return true;
            }
        }

        return isSubTree(rootA.left, rootB) || isSubTree(rootA.right, rootB);
    }

    public boolean isMatch(TreeNode rootA, TreeNode rootB) {
        if (rootA == null && rootB == null) {
            return true;
        }

        if (rootA == null || rootB == null) {
            return false;
        }

        if (rootA.val != rootB.val) {
            return false;
        }

        return isMatch(rootA.left, rootB.left) && isMatch(rootB.right, rootB.right);
    }

    public static void main(String[] args) {
        String treeARaw = "1,2,2,3,3,3,3,4,4,4,4,4,4,#,#,5,5";
        String treeBRaw = "3,4,4";
        String treeCRaw = "4,#,5";
        String treeDRaw = "2,4";
        BinaryTreeCodec codec = new BinaryTreeCodec();
        TreeNode treeA = codec.fromBSTString(treeARaw);
        TreeNode treeB = codec.fromBSTString(treeBRaw);
        TreeNode treeC = codec.fromBSTString(treeCRaw);
        TreeNode treeD = codec.fromBSTString(treeDRaw);
        System.out.println(new FindTreeInTree().isSubTree(treeA, treeB));
        System.out.println(new FindTreeInTree().isSubTree(treeA, treeC));
        System.out.println(new FindTreeInTree().isSubTree(treeA, treeD));
    }
}
