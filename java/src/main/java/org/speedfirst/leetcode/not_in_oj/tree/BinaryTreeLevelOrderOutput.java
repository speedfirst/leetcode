package org.speedfirst.leetcode.not_in_oj.tree;

import org.speedfirst.leetcode.basic.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by jiankuan on 1/27/15.
 */
public class BinaryTreeLevelOrderOutput {

    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        int i = 0;
        while (true) {
            ArrayList<Integer> level = new ArrayList<>();
            if (doLevelOrder(root, 0, i, level)) {
                res.add(level);
            } else {
                break;
            }
            i++;
        }
        return res;
    }

    private boolean doLevelOrder(TreeNode root, int curHeight, int targetHeight, List<Integer> level) {
        if (root == null) {
            return false;
        }
        if (curHeight == targetHeight) {
            level.add(root.val);
            return true;
        }

        if (curHeight > targetHeight) {
            return false;
        }

        boolean leftEnd = doLevelOrder(root.left, curHeight + 1, targetHeight, level);

        boolean rightEnd = doLevelOrder(root.right, curHeight + 1, targetHeight, level);

        return leftEnd || rightEnd;
    }

    public static void main(String[] args) {
        TreeNode root = new BinaryTreeCodec().fromBSTString("3,9,20,#,#,15,7");
        ArrayList<ArrayList<Integer>> res = new BinaryTreeLevelOrderOutput().levelOrder(root);
        for (ArrayList<Integer> list: res) {
            System.out.println(list);
        }
    }
}
