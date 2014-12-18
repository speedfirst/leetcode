package org.speedfirst.leetcode.math;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author jiankuan
 * @date 12/18/14
 */
public class FractionToRecurringDecimal {


    public String fractionToDecimal(int numerator, int denominator) {
        long n = numerator;
        long d = denominator;
        if (d == 0) return "+INF";

        StringBuilder sb = new StringBuilder();
        if ((n < 0 && d > 0) || (n > 0 && d < 0)) {
            sb.append("-");
        }
        n = Math.abs(n);
        d = Math.abs(d);

        long integerPart = n / d;
        sb.append(integerPart);
        n = n % d;
        if (n == 0) return sb.toString();
        else sb.append(".");

        Integer loopStart = null;
        Map<Long, Integer> nominator2digitIdx = new HashMap<>();
        List<Integer> prevDigits = new ArrayList<>();
        int pos = 0;
        while (n != 0) {
            loopStart = nominator2digitIdx.get(n);
            if (loopStart != null) {
                break;
            }
            nominator2digitIdx.put(n, pos++);
            n *= 10;
            prevDigits.add((int) (n / d));
            n %= d;
        }

        if (loopStart != null) {
            for (int i = 0; i < loopStart; i++) {
                sb.append(prevDigits.get(i));
            }
            sb.append("(");
            for (int i = loopStart; i < prevDigits.size(); i++) {
                sb.append(prevDigits.get(i));
            }
            sb.append(")");
        } else {
            for (int i = 0; i < prevDigits.size(); i++) {
                sb.append(prevDigits.get(i));
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        String res = new FractionToRecurringDecimal().fractionToDecimal(1, 98);
        System.out.println(res);
    }
}
