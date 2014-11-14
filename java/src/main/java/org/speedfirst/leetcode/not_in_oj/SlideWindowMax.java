package org.speedfirst.leetcode.not_in_oj;

import java.util.*;

/**
 * Created by jiankuan on 11/14/14.
 */
public class SlideWindowMax {

    class Element {

        public Element(int index, int value) {
            this.index = index;
            this.value = value;
        }
        public int index;

        public int value;
    }

    public List<Integer> getSlideWindowMaxHead(List<Integer> arr, int k) {
        PriorityQueue<Element> queue = new PriorityQueue<Element>(
                new Comparator<Element>() {
                    @Override
                    public int compare(Element o1, Element o2) {
                        return o2.value - o1.value;
                    }
                });
        List<Integer> res = new ArrayList<Integer>();

        for (int i = 0; i < k; i++) {
            queue.offer(new Element(i, arr.get(i)));
        }

        for (int i = k; i < arr.size(); i++) {
            Element top;
            do {
                top = queue.peek();
                if (top.index >= i - k) {
                    break;
                }
                queue.poll();
            } while (!queue.isEmpty());
            res.add(top.value);
            queue.add(new Element(i, arr.get(i)));
        }

        res.add(queue.peek().value);

        return res;
    }

    public List<Integer> getSlideWindowMaxDeque(List<Integer> arr, int k) {
        Deque<Integer> queue = new LinkedList<Integer>(); // in the deque we save the idx of element
        List<Integer> res = new ArrayList<Integer>();

        for (int i = 0; i < k; i++) {
            int cur = arr.get(i);
            while (!queue.isEmpty() && arr.get(queue.peekLast()) <= cur) {
                queue.pollLast();
            }
            queue.offerLast(i);
        }

        for (int i = k; i < arr.size(); i++) {
            res.add(arr.get(queue.getFirst()));
            while (queue.peekFirst() <= i - k) {
                queue.pollFirst();
            }

            int cur = arr.get(i);
            while (!queue.isEmpty() && arr.get(queue.peekLast()) <= cur) {
                queue.pollLast();
            }
            queue.offerLast(i);
        }

        res.add(arr.get(queue.getFirst()));

        return res;
    }

    public static void main(String[] args) {
        System.out.println("==========Heap===========");
        List<Integer> arr = Arrays.asList(1, 3, -1, -3, 5, 3, 6, 7);
        List<Integer> res = new SlideWindowMax().getSlideWindowMaxHead(arr, 3);
        for (int num: res) {
            System.out.print(num);
            System.out.print(", ");
        }
        System.out.println();
        System.out.println("===========Deque==========");
        List<Integer> res2 = new SlideWindowMax().getSlideWindowMaxDeque(arr, 3);
        for (int num: res2) {
            System.out.print(num);
            System.out.print(", ");
        }
        System.out.println();
    }

}
