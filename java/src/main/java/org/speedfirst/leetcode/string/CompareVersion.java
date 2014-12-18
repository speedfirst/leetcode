package org.speedfirst.leetcode.string;

/**
 * @author jiankuan
 * @date 12/16/14
 */
public class CompareVersion {

    public int compareVersion(String version1, String version2) {
        String[] ver1s = version1.split("\\.");
        String[] ver2s = version2.split("\\.");
        int i = 0;
        for (; i < Math.min(ver1s.length, ver2s.length); i++) {
            int ver1 = Integer.valueOf(ver1s[i]);
            int ver2 = Integer.valueOf(ver2s[i]);
            if (ver1 > ver2) return 1;
            if (ver1 < ver2) return -1;
        }

        if (ver1s.length > i) return 1;
        if (ver2s.length > i) return -1;
        return 0;
    }

    public static void main(String[] args) {
        int res = new CompareVersion().compareVersion("1", "0");
        System.out.println(res);
    }

}
