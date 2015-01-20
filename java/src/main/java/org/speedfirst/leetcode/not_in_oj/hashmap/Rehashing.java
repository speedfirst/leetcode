package org.speedfirst.leetcode.not_in_oj.hashmap;

import org.speedfirst.leetcode.basic.ListNode;

/**
 * Created by jiankuan on 1/21/15.
 */
public class Rehashing {

    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    public ListNode[] rehashing(ListNode[] hashTable) {
        int n = hashTable.length;
        int m = 2 * n;
        ListNode[] newHashTable = new ListNode[m];

        for (ListNode head: hashTable) {
            ListNode cur = head;
            ListNode next = null;
            while (cur != null) {
                next = cur.next;
                int newPos = mod(cur.val, m);
                if (newHashTable[newPos] == null) {
                    newHashTable[newPos] = cur;
                    cur.next = null;
                } else {
                    ListNode newCur = newHashTable[newPos];
                    // find tail, talk with your interviewer to confirm whether it's necessary to append to the tail
                    while (newCur.next != null) {
                        newCur = newCur.next;
                    }
                    newCur.next = cur;
                    cur.next = null;
                }
                cur = next;
            }
        }

        return newHashTable;
    }

    private int mod(int a, int b) {
        if (a >= 0) {
            return a % b;
        } else {
            return (a % b + b) % b;
        }
    }
}
