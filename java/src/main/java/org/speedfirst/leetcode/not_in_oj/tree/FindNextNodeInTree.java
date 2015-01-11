package org.speedfirst.leetcode.not_in_oj.tree;

import org.speedfirst.leetcode.basic.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * @author jiankuan
 * @since 1/11/15
 */
public class FindNextNodeInTree {

    // only know the current node. Node has parent
    public TreeNode nextNode(TreeNode cur) {
        if (cur == null) {
            return null;
        }

        if (cur.right != null) {
            return leftMostNode(cur.right);
        }

        while (true) {
            TreeNode parent = cur.parent;
            if (parent == null) {
                return null;
            }
            if (cur == parent.left) {
                return parent;
            } else { // cur == parent.right
                cur = parent;
            }
        }
    }

    // know the root of the tree, the tree is BST, can't use "parent"
    public TreeNode nextNode(TreeNode root, TreeNode target) {
        if (target == null) {
            return null;
        }

        if (target == root) {
            return leftMostNode(root.right);
        }

        // search the node by BST
        TreeNode cur = root;
        List<TreeNode> path = new ArrayList<>();
        while (cur != null) {
            if (cur.val > target.val) {
                path.add(cur);
                cur = cur.left;
            } else if (cur.val < target.val) {
                path.add(cur);
                cur = cur.right;
            } else {
                // found it
                break;
            }
        }

        assert (!path.isEmpty());

        if (cur == null) {
            // not found
            return null;
        }

        if (cur.right != null) {
            return leftMostNode(cur.right);
        }

        int idx = path.size() - 1;
        while (idx >= 0) {
            TreeNode parent = path.get(idx);
            if (cur == parent.left) {
                return parent;
            } else {
                idx--;
                cur = parent;
            }
        }

        return null;
    }

    public TreeNode leftMostNode(TreeNode n) {
        if (n == null) {
            return null;
        }

        while (n.left != null) {
            n = n.left;
        }

        return n;
    }

    public static void main(String[] args) {
        System.out.println("========= Binary Tree + parent pointer, case 1 ======");

        String treeRaw = "1,2,3,#,#,4,#,#,5";
        TreeNode root = new BinaryTreeCodec().fromBSTString(treeRaw);
        FindNextNodeInTree findNextNodeInTree = new FindNextNodeInTree();
        TreeNode cur = root.left;
        // expect 2, 1, 4, 5, 3, null, null, ...
        for (int i = 0; i < 8; i++) {
            System.out.println(cur);
            cur = findNextNodeInTree.nextNode(cur);
        }

        System.out.println("========= Binary Tree + parent pointer, case 2 ======");

        String treeRaw2 = "4,2,5,1,3,#,6";
        TreeNode root2 = new BinaryTreeCodec().fromBSTString(treeRaw2);
        TreeNode cur2 = findNextNodeInTree.leftMostNode(root2);

        // expect 1, 2, 3, 4, 5, 6, null, null, ...
        for (int i = 0; i < 8; i++) {
            System.out.println(cur2);
            cur2 = findNextNodeInTree.nextNode(cur2);
        }

        System.out.println("======== BST + No parent pointer ==========");
        String treeRaw3 = "4,2,5,1,3,#,6";
        TreeNode root3 = new BinaryTreeCodec().fromBSTString(treeRaw3);
        TreeNode cur3 = findNextNodeInTree.leftMostNode(root3);

        // expect 1, 2, 3, 4, 5, 6, null, null, ...
        for (int i = 0; i < 8; i++) {
            System.out.println(cur3);
            cur3 = findNextNodeInTree.nextNode(root3, cur3);
        }
    }
}
