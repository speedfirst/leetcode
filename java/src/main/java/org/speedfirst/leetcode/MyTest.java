package org.speedfirst.leetcode;

/**
 * @author jiankuan
 * @since 12/29/14
 */
public class MyTest {

    public static void main(String[] args) {
        String abc = "abc";
        String def = "def";
        String empty1 = abc.substring(0, 0);
        String empty2 = def.substring(0, 0);
        System.out.println(empty1);
        System.out.println(empty2);
        System.out.println(empty1.intern() == empty2.intern());
    }
}
