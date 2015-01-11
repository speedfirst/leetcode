package org.speedfirst.leetcode.basic;

/**
 * Created by jiankuan on 11/4/14.
 */
public class TreeNode {
    public int val;

    public TreeNode left;

    public TreeNode right;

    public TreeNode parent;

    public TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
        this.parent = null;
    }

    @Override
    public String toString() {
        return String.valueOf(val);
    }

}
