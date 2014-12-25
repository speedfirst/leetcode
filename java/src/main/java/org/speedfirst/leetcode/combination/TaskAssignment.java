package org.speedfirst.leetcode.combination;

import java.util.*;

/**
 * @author jiankuan
 * @since 12/24/14
 */
public class TaskAssignment {

    List<Map<Integer, List<Integer>>> assigments = new ArrayList<>();

    /**
     * generate an assignment
     * @param n number of tasks
     * @param m number of
     * @return the assignment
     */
    public Map<Integer, List<Integer>> assign(int n, int m) {
        Map<Integer, List<Integer>> assignment = new HashMap<>();
        for (int i = 0; i < m; i++) {
            assignment.put(i, new ArrayList<>());
        }
        doAssign(n, m, 0, 0, assignment);

        int i = 1;
        for (Map<Integer, List<Integer>> a: assigments) {
            System.out.println("========= " + i + " ==========");
            i++;
            output(a);
        }
        return assignment;
    }

    private void doAssign(int n, int m, int curTask, int curMachine,  Map<Integer, List<Integer>> assignment) {
        if (curTask == n) {
            assigments.add(makeCopy(assignment));
            return;
        }


        for (int i = curMachine; i < m; i++) {
            List<Integer> list = assignment.get(i);
            list.add(curTask);
            doAssign(n, m, curTask + 1, curMachine + 1, assignment);
            list.remove(list.size() - 1);
        }
    }

    private Map<Integer, List<Integer>> makeCopy(Map<Integer, List<Integer>> src) {
        Map<Integer, List<Integer>> res = new HashMap<>(src.size());
        for (Map.Entry<Integer, List<Integer>> entry: src.entrySet()) {
            res.put(entry.getKey(), new ArrayList<>(entry.getValue()));
        }
        return res;
    }

    private void output(Map<Integer, List<Integer>> assignment) {
        Set<Integer> machines = new TreeSet<>(assignment.keySet());
        for (int i: machines) {
            System.out.print(i + ": ");
            for (int j: assignment.get(i)) {
                System.out.print(j + ", ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        TaskAssignment taskAssignment = new TaskAssignment();
        taskAssignment.assign(3, 3);
    }
}
