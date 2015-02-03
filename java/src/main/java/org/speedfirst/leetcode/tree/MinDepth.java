package org.speedfirst.leetcode.tree;

import org.speedfirst.leetcode.basic.TreeNode;
import org.speedfirst.leetcode.not_in_oj.tree.BinaryTreeCodec;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by jiankuan on 2/3/15.
 */
public class MinDepth {

    /**
     * @param root: The root of binary tree.
     * @return: An integer.
     */
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        queue.offer(null);
        int res = 1;
        while (!queue.isEmpty()) {
            TreeNode curNode = queue.poll();
            if (curNode == null) {
                res++;
                queue.offer(null);
                continue;
            }
            if (curNode.left == null && curNode.right == null) {
                break;
            }

            if (curNode.left != null) {
                queue.offer(curNode.left);
            }

            if (curNode.right != null) {
                queue.offer(curNode.right);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        TreeNode root = new BinaryTreeCodec().fromBSTString("1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16");
        MinDepth minDepth = new MinDepth();
        int res = minDepth.minDepth(root);
        System.out.println(res);
    }

}
