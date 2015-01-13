package org.speedfirst.leetcode.dp;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Given a list of items, each of which contains two values, find the max length of sub list which both values are
 * monotone increasing.
 *
 * @author jiankuan
 * @since 1/13/15
 */
public class MaxIncrementalRangeOfTwoDimensionArray {
    static class Item {
        public Item(int val1, int val2) {
            this.val1 = val1;
            this.val2 = val2;
        }
        public int val1;
        public int val2;

        @Override
        public String toString() {
            return "(" + val1 + "," + val2 + ")";
        }
    }

    static class ItemComparator implements java.util.Comparator<Item> {

        @Override
        public int compare(Item item1, Item item2) {
            if (item1.val1 != item1.val1) {
                return item1.val1 - item2.val1;
            }

            return item1.val2 - item2.val2;
        }
    }

    public int getMaxLength(List<Item> items) {
        Collections.sort(items, new ItemComparator());
        int[] dp = new int[items.size()];
        Arrays.fill(dp, 1);
        for (int i = 1; i < items.size(); i ++) {
            Item curItem = items.get(i);
            for (int j = i - 1; j >= 0; j--) {
                Item prevItem = items.get(j);
                if (curItem.val1 >= prevItem.val1 && curItem.val2 >= prevItem.val2) {
                    dp[i] = dp[j] + 1;
                    break;
                }
            }
        }

        return dp[items.size() - 1];
    }

    public static void main(String[] args) {
        Item i1 = new Item(60, 100);
        Item i2 = new Item(70, 150);
        Item i3 = new Item(56, 90);
        Item i4 = new Item(75, 190);
        Item i5 = new Item(60, 95);
        Item i6 = new Item(68, 110);
        List<Item> items = Arrays.asList(i1, i2, i3, i4, i5, i6);

        int res = new MaxIncrementalRangeOfTwoDimensionArray().getMaxLength(items);
        System.out.println(res);

    }
}
