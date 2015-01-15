package org.speedfirst.leetcode.not_in_oj.list;

import org.speedfirst.leetcode.basic.ListNode;

/**
 * Give a linked list L1->L2->L3->....->M1->M2->M3->... (M1 is the mid point of the linked list), convert it to
 * L1->M1->L2->M2->L3->M3->...
 *
 * For example:
 * 1->2->3->4        ==>  1->3->2->4
 * 1->2->3->4->5     ==>  1->3->2->4->5
 * 1->2->3->4->5->6  ==>  1->4->2->5->3->6
 * @author jiankuan
 * @since 1/15/15
 */
public class ReorderList {

    public ListNode reorderList(ListNode root) {
        if (root == null || root.next == null || root.next.next == null) {
            return root;
        }

        int len = 0;
        ListNode cur = root;
        while (cur != null) {
            len++;
            cur = cur.next;
        }

        int mid = (len / 2) - 1; // pos of the prev node of the mid node
        ListNode prevM = root;
        while (mid > 0) {
            prevM = prevM.next;
            mid--;
        }

        ListNode curM = prevM.next;
        ListNode prev = root;

        while (prev != prevM) {
            prevM.next = curM.next;
            curM.next = prev.next;
            prev.next = curM;
            prev = curM.next;
            curM = prevM.next;
        }

        return root;
    }

    public static void main(String[] args) {
        ReorderList rl = new ReorderList();
        ListNode.output(rl.reorderList(ListNode.of()));
        ListNode.output(rl.reorderList(ListNode.of(1)));
        ListNode.output(rl.reorderList(ListNode.of(1, 2)));
        ListNode.output(rl.reorderList(ListNode.of(1, 2, 3)));
        ListNode.output(rl.reorderList(ListNode.of(1, 2, 3, 4)));
        ListNode.output(rl.reorderList(ListNode.of(1, 2, 3, 4, 5)));
        ListNode.output(rl.reorderList(ListNode.of(1, 2, 3, 4, 5, 6)));
    }
}
