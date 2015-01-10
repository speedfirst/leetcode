package org.speedfirst.leetcode.not_in_oj;

import java.util.NoSuchElementException;
import java.util.Stack;

/**
 * A queue implemented by static
 * @author jiankuan
 * @since 1/10/15
 */
public class StackBasedQueue {

    private Stack<Integer> s1 = new Stack<>();
    private Stack<Integer> s2 = new Stack<>();

    public void offer(int val) {
        s1.push(val);
    }

    public int poll() {
        if (s1.isEmpty() && s2.isEmpty()) {
            throw new NoSuchElementException();
        }

        if (!s2.isEmpty()) {
            return s2.pop();
        }

        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }

        return s2.pop();
    }

    public static void main(String[] args) {
        StackBasedQueue queue = new StackBasedQueue();
        queue.offer(1);
        queue.offer(2);
        queue.offer(3);
        System.out.println(queue.poll());
        System.out.println(queue.poll());
        queue.offer(4);
        queue.offer(5);
        System.out.println(queue.poll());
        System.out.println(queue.poll());
        queue.offer(6);
        queue.offer(7);
        System.out.println(queue.poll());
        System.out.println(queue.poll());
        System.out.println(queue.poll());
    }
}
