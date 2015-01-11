package org.speedfirst.leetcode.combination;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Generate all the subsets of a set
 * @author jiankuan
 * @since 1/11/15
 */
public class AllSubSets {

    /**
     * generate subsets by a binary integer. When a bit is 1, opt in the elements in the original set.
     * This approach can be used if set.size() <= 63 assuming we're using a long value. In Java, there is
     * a EnumSet which can be used here.
     */
    public List<List<Integer>> gentSubsetsByBinaryNumber(List<Integer> set) {
        int max = 1 << set.size();
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < max; i++) {
            List<Integer> subSet = new ArrayList<>();
            int idx = 0;
            while (idx < set.size()) {
                if (((i >> idx) & 1) == 1) {
                    subSet.add(set.get(idx));
                }
                idx++;
            }
            res.add(subSet);
        }

        return res;
    }

    /**
     * Generate subsets by recursion.
     */
    public List<List<Integer>> genSubsetsByRecursion(List<Integer> set) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> curSubSet = new ArrayList<>();
        doGenSubsetsByRecursion(set, curSubSet, res, 0);
        return res;
    }

    private void doGenSubsetsByRecursion(List<Integer> set, List<Integer> curSubSet, List<List<Integer>> res, int curPos) {
        if (curPos == set.size()) {
            res.add(new ArrayList<>(curSubSet));
            return;
        }

        for (int i = curPos; i < set.size(); i++) {
            curSubSet.add(set.get(i));
            doGenSubsetsByRecursion(set, curSubSet, res, i + 1);
            curSubSet.remove(curSubSet.size() - 1);
        }
    }

    /**
     * Generate subsets by iteration
     */
    public List<List<Integer>> genSubsetsByIteration(List<Integer> set) {
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<>()); // add an initial empty set
        for (int i = 0; i < set.size(); i++) {
            int len = res.size();
            for (int j = 0; j < len; j++) {
                List<Integer> newSubSet = new ArrayList<>(res.get(j));
                newSubSet.add(set.get(i));
                res.add(newSubSet);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        List<Integer> set = Arrays.asList(1, 2, 3, 4, 5);
        AllSubSets allSubSets = new AllSubSets();
        System.out.println("========== by binary ==============");
        List<List<Integer>> subsets = allSubSets.gentSubsetsByBinaryNumber(set);
        outputSubsets(subsets);
        System.out.println("========== by recursion ===========");
        List<List<Integer>> subsets2 = allSubSets.genSubsetsByRecursion(set);
        outputSubsets(subsets2);
        System.out.println("========== by iteration ===========");
        List<List<Integer>> subsets3 = allSubSets.genSubsetsByIteration(set);
        outputSubsets(subsets3);
    }

    private static void outputSubsets(List<List<Integer>> subsets) {
        for (List<Integer> subset: subsets) {
            StringBuilder sb = new StringBuilder();
            sb.append("[");
            for (int num: subset) {
                sb.append(num);
                sb.append(",");
            }
            if (sb.charAt(sb.length() - 1) == ',') {
                sb.setLength(sb.length() - 1);
            }
            sb.append("]");
            System.out.println(sb.toString());
        }
    }
}
