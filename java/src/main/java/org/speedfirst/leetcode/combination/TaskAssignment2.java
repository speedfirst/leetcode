package org.speedfirst.leetcode.combination;

import java.util.ArrayList;
import java.util.List;

/**
 * Assign n tasks to m machines. Tasks and machines are considered equal.
 * This is actually a number split problem
 *
 * @author jiankuan
 * @since 12/25/14
 */
public class TaskAssignment2 {


    private void split(int n, int m, int curPos, List<Integer> curAssignment, List<List<Integer>> assignment) {

        if (curPos == m) {
            if (n == 0) { // we just separate n to m parts
                assignment.add(new ArrayList<>(curAssignment));
            }
            return;
        }

        int start;
        if (curPos > 0) {
            start = curAssignment.get(curPos - 1); // to avoid duplication. Each time we start from a value >= prev
        } else {
            start = 0;
        }

        for (int i = start; i <= n; i++) {
            curAssignment.set(curPos, i);
            if (i > n) break;
            split(n - i, m, curPos + 1, curAssignment, assignment);
        }

    }

    /**
     *
     * @param n n tasks
     * @param m m machines
     * @return a list of assignments. Each element is how many tasks are assigned to a machine
     */
    public List<List<Integer>> assign(int n, int m)  {
        List<List<Integer>> assignments = new ArrayList<>();
        List<Integer> curAssignment = new ArrayList<>(m);
        for (int i = 0; i < m; i++) {
            curAssignment.add(0);
        }
        split(n, m, 0, curAssignment, assignments);
        return assignments;
    }

    public static void main(String[] args) {
        List<List<Integer>> assignments = new TaskAssignment2().assign(5, 4);
        for (int i = 0; i < assignments.size(); i++) {
            System.out.println("======== " + i + " =========");
            for (int j: assignments.get(i)) {
                System.out.print(j + ", ");
            }
            System.out.println();
        }
    }
}
