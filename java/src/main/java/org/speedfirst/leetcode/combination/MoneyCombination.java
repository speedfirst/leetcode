package org.speedfirst.leetcode.combination;

import java.util.ArrayList;
import java.util.List;

/**
 * You have infinite 25 cents, 10 cents, 5 cents, 1 cents. Give a number, output all the combinations which can
 * get that number.
 *
 * @author jiankuan
 * @since 1/12/15
 */
public class MoneyCombination {

    public List<List<Integer>> getMoneyCombination(int sum) {
        List<List<Integer>> res = new ArrayList<>();
        doGetMoneyCombination(sum, 0, new ArrayList<>(), res);
        return res;
    }

    private int[] moneySet = {25, 10, 5, 1};


    private void doGetMoneyCombination(int sum, int pos, List<Integer> curComb, List<List<Integer>> res) {
        if (sum < 0) {
            return;
        }

        if (sum == 0) {
            res.add(new ArrayList<>(curComb));
            return;
        }

        for (int i = pos; i < moneySet.length; i++) {
            int money = moneySet[i];
            curComb.add(money);
            doGetMoneyCombination(sum - money, i, curComb, res);
            curComb.remove(curComb.size() - 1);
        }
    }

    public static void main(String[] args) {
        List<List<Integer>> res = new MoneyCombination().getMoneyCombination(100);
        System.out.println(res.size());
        for (List<Integer> comb: res) {
            System.out.println(comb);
        }
    }
}
