package org.speedfirst.leetcode.basic;

/**
 * Created by jiankuan on 11/4/14.
 */
public class ListNode {

    public int val;

    public ListNode next;

    public ListNode(int val) {
        this.val = val;
        this.next = null;
    }

    public static void output(ListNode root) {
        if (root == null) {
            System.out.println("(empty)");
            return;
        }
        ListNode cur = root;
        StringBuilder sb = new StringBuilder();
        while (cur != null) {
            sb.append(cur.val);
            sb.append("->");
            cur = cur.next;
        }

        if (sb.length() > 0) {
            sb.setLength(sb.length() - 2);
        }

        System.out.println(sb.toString());
    }

    public static ListNode of(int... nums) {
        if (nums.length == 0) {
            return null;
        }

        ListNode head = new ListNode(nums[0]);
        ListNode prev = head;
        for (int i = 1; i < nums.length; i++) {
            ListNode n = new ListNode(nums[i]);
            prev.next = n;
            prev = prev.next;
        }

        return head;
    }
}
