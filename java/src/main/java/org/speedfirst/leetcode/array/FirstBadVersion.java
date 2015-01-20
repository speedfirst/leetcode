package org.speedfirst.leetcode.array;

import java.util.function.Function;

/**
 * Created by jiankuan on 1/20/15.
 */
public class FirstBadVersion {

    public int findFirstBadVersoin(int n, Function<Integer, Boolean> isBadVersion) {
        int s = 1;
        int e = n;
        while (s < e) {
            int mid = (s + e) / 2;
            if (isBadVersion.apply(mid)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        if (isBadVersion.apply(s)) {
            return s;
        } else {
            return -1;
        }
    }


    public static void main(String[] args) {
        FirstBadVersion firstBadVersion = new FirstBadVersion();
        int res = firstBadVersion.findFirstBadVersoin(31, n -> true);
        System.out.println(res);
    }
}
