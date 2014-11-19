package org.speedfirst.leetcode.not_in_oj;

import java.util.Stack;

/**
 * Sort numbers in stack
 */
public class StackSort {
    // use only push, pop peek to sort a stack
    public Stack<Integer> sort(Stack<Integer> s) {
        Stack<Integer> r = new Stack<>();
        while (!s.empty()) {
            int cur = s.pop();
            if (!r.empty() && cur < r.peek()) {
                while(!r.empty()) {
                    int tmp = r.pop();
                    s.push(tmp);
                }
            }
            r.push(cur);
        }

        return r;
    }

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(4);
        s.push(2);
        s.push(8);
        s.push(1);
        s.push(6);

        Stack<Integer> r = new StackSort().sort(s);
        for (int i : r) {
            System.out.println(i);
        }
    }
}
