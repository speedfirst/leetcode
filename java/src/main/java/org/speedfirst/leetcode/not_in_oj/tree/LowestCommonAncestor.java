package org.speedfirst.leetcode.not_in_oj.tree;

import org.speedfirst.leetcode.basic.TreeNode;

/**
 * Created by jiankuan on 1/27/15.
 */
public class LowestCommonAncestor {

    public static final int hasNone = 0;

    public static final int hasA = 1;

    public static final int hasB = 2;

    public static final int hasBoth = 3;

    public static final int resGened = 4;

    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode A, TreeNode B) {
        TreeNode[] res = new TreeNode[1];
        res[0] = null;
        doLCA(root, A, B, res);
        return res[0];
    }

    public int doLCA(TreeNode root, TreeNode A, TreeNode B, TreeNode[] res) {
        if (root == null) {
            return hasNone;
        }

        int resCode = 0;
        if (root.val == A.val) {
            resCode |= hasA;
        }

        if (root.val == B.val) {
            resCode |= hasB;
        }

        if (resCode == hasBoth) {
            res[0] = root;
            return hasBoth;
        }

        int leftResCode = doLCA(root.left, A, B, res);
        if (leftResCode == resGened) {
            return resGened;
        }

        if ((leftResCode | resCode) == hasBoth) {
            res[0] = root;
            return resGened;
        }

        int rightResCode = doLCA(root.right, A, B, res);
        if (rightResCode == resGened) {
            return resGened;
        }

        if ((leftResCode | rightResCode | resCode) == hasBoth) {
            res[0] = root;
            return resGened;
        }

        return leftResCode | rightResCode | resCode;
    }

    public static void main(String[] args) {
        TreeNode root = new BinaryTreeCodec().fromBSTString("1,#,2,#,3,#,4,#,5");
        LowestCommonAncestor lca = new LowestCommonAncestor();
        TreeNode A = new TreeNode(3);
        TreeNode B = new TreeNode(5);
        TreeNode n = lca.lowestCommonAncestor(root, A, B);
        System.out.println(n);
    }
}
