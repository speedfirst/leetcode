package org.speedfirst.leetcode.math;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Given the k-th number which only has 3, 5 or 7 factors. The list
 * looks like:
 * <pre>
 *     1, 3, 5, 7, 9, 15, 21, 25, 27, ...
 * </pre>
 * @author jiankuan
 * @since 1/13/15
 */
public class GetKthMagicNumber {

    public int  getKthMagicNumber(int k) {

        if (k <= 0) {
            throw new IllegalArgumentException();
        }

        Queue<Integer> q3 = new LinkedList<>();
        Queue<Integer> q5 = new LinkedList<>();
        Queue<Integer> q7 = new LinkedList<>();

        q3.offer(3);
        q5.offer(5);
        q7.offer(7);

        int val = 1;
        while (k > 1) {
            Queue<Integer> q = getQueueWithMinValue(q3, q5, q7);
            val = q.poll();
            q3.offer(val * 3);  // Note avoid duplication here. For instance, you got 5 from q5, do not append 5 * 3 to q3
                                // because before you have already append 3 * 5 to q5.
            if (q == q5 || q == q7) {
                q5.offer(val * 5);
                if (q == q7) {
                    q7.offer(val * 7);
                }
            }
            k--;
        }
        return val;
    }

    private int[] buffer = new int[3];

    private Queue getQueueWithMinValue(Queue<Integer> q3, Queue<Integer> q5, Queue<Integer> q7) {
        buffer[0] = q3.peek();
        buffer[1] = q5.peek();
        buffer[2] = q7.peek();

        int minIdx = 0;
        for (int i = 1; i < 3; i++) {
            if (buffer[minIdx] > buffer[i]) {
                minIdx = i;
            }
        }

        switch (minIdx) {
            case 0:
                return q3;
            case 1:
                return q5;
            case 2:
                return q7;
        }

        return null;
    }

    public static void main(String[] args) {
        GetKthMagicNumber sol = new GetKthMagicNumber();
        System.out.println(sol.getKthMagicNumber(1));
        System.out.println(sol.getKthMagicNumber(2));
        System.out.println(sol.getKthMagicNumber(3));
        System.out.println(sol.getKthMagicNumber(4));
        System.out.println(sol.getKthMagicNumber(5));
        System.out.println(sol.getKthMagicNumber(6));
        System.out.println(sol.getKthMagicNumber(7));
        System.out.println(sol.getKthMagicNumber(8));
        System.out.println(sol.getKthMagicNumber(9));
        System.out.println(sol.getKthMagicNumber(10));
        System.out.println(sol.getKthMagicNumber(11));
        System.out.println(sol.getKthMagicNumber(12));
        System.out.println(sol.getKthMagicNumber(13));
        System.out.println(sol.getKthMagicNumber(14));
        System.out.println(sol.getKthMagicNumber(15));
    }
}
