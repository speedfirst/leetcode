package org.speedfirst.leetcode.list.merge_two_sorted_list;

import org.speedfirst.leetcode.basic.ListNode;

/**
 * Created by jiankuan on 11/4/14.
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            return null;
        }

        if (l1 == null) {
            return l2;
        }

        if (l2 == null) {
            return l1;
        }

        ListNode cur1 = l1;
        ListNode cur2 = l2;
        ListNode ret = new ListNode(-1);
        ListNode cur = ret;

        while (cur1 != null && cur2 != null) {
            if (cur1.val < cur2.val) {
                cur.next = cur1;
                cur1 = cur1.next;
            } else {
                cur.next = cur2;
                cur2 = cur2.next;
            }
            cur = cur.next;
        }

        if (cur1 == null) {
            cur.next = cur2;
        } else {
            cur.next = cur1;
        }

        return ret.next;
    }
}
