package org.speedfirst.leetcode.not_in_oj;

import org.speedfirst.leetcode.basic.TreeNode;

import java.util.Stack;

/**
 * Created by jiankuan on 10/28/14.
 */
public class TreeIterator {

    public TreeNode root;

    private Stack<TreeNode> s = new Stack<TreeNode>();


    public TreeIterator(TreeNode root) {
        this.root = root;
        TreeNode cur = this.root;
        while (cur != null) {
            s.push(cur);
            cur = cur.left;
        }
    }

    public TreeNode next() {
        if (s.empty()) {
            return null;
        }

        TreeNode res = s.pop();
        TreeNode next = res.right;
        while (next != null) {
            s.push(next);
            next = next.left;
        }
        return res;
    }
}
