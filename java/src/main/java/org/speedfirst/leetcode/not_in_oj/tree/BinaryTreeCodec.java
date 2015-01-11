package org.speedfirst.leetcode.not_in_oj.tree;

import org.speedfirst.leetcode.basic.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Serializer/Deserializer
 *
 * @author jiankuan
 * @since 1/10/15
 */
public class BinaryTreeCodec {

    /**
     * parse the string serialized in BFS serialization (how leetcode serialize a binary tree, but not contains "{ }")
     */
    public TreeNode fromBSTString(String raw) {
        if (raw == null || raw.length() == 0) {
            return null;
        }

        String[] secs = raw.split(",");
        TreeNode root = new TreeNode(Integer.valueOf(secs[0]));
        root.parent = null;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int idx = 1;
        while (idx < secs.length) {
            TreeNode cur = queue.poll();
            String valStr = secs[idx];
            if (valStr.equals("#")) {
                cur.left = null;
            } else {
                cur.left = new TreeNode(Integer.valueOf(valStr));
                cur.left.parent = cur;
                queue.offer(cur.left);
            }
            idx++;

            if (idx == secs.length) break;

            valStr = secs[idx];
            if (valStr.equals("#")) {
                cur.right = null;
            } else {
                cur.right = new TreeNode(Integer.valueOf(valStr));
                cur.right.parent = cur;
                queue.offer(cur.right);
            }
            idx++;
        }

        assert (queue.isEmpty());
        return root;
    }

    public String toBSTString(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        if (root == null) {
            return sb.toString();
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {

            TreeNode cur = queue.poll();
            if (cur == null) {
                sb.append("#");
            } else {
                sb.append(cur.val);
                if (queue.isEmpty() && cur.left == null && cur.right == null) {
                    break; // omit the last 2 '#'
                }
                queue.offer(cur.left);
                queue.offer(cur.right);

            }
            sb.append(",");
        }

        if (sb.charAt(sb.length() - 1) == ',') {
            sb.setLength(sb.length() - 1);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        String raw = "1,2,3,#,#,4,#,#,5";
        TreeNode root = new BinaryTreeCodec().fromBSTString(raw);
        String raw2 = new BinaryTreeCodec().toBSTString(root);
        System.out.println(raw);
        System.out.println(raw2);
    }
}
