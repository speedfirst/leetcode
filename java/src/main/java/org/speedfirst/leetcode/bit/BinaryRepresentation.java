package org.speedfirst.leetcode.bit;

/**
 * Created by jiankuan on 1/21/15.
 */
public class BinaryRepresentation {

    public String binaryRepresentation(String n) {
        if (n.length() == 0) {
            return n;
        }

        boolean positive = true;
        if (n.charAt(0) == '-') {
            n = n.substring(1, n.length());
            positive = false;
        }
        int pos = n.indexOf('.');
        if (pos == -1) {
            String res = intToBin(n);
            if (!positive) {
                return "-" + res;
            } else {
                return res;
            }
        } else {
            String digitStr = digitToBin(n.substring(pos));
            if (digitStr == null) {
                return "ERROR";
            }
            String intStr = intToBin(n.substring(0, pos));
            String res;
            if (digitStr.equals("0")) {
                res = intStr;
            } else {
                res = intStr + "." + digitStr;
            }
            if (!positive) {
                return "-" + res;
            } else {
                return res;
            }
        }
    }

    private String intToBin(String n) {
        StringBuilder sb = new StringBuilder();
        long num = Long.parseLong(n);
        if (num == 0) {
            return "0";
        }
        while (num > 0) {
            int digit = (int)(num & 0x01);
            sb.append(digit);
            num >>= 1;
        }

        return sb.reverse().toString();
    }

    private String digitToBin(String n) {
        double num = Double.parseDouble(n); // Note, you can't use integer cal here. Integer is too accurate to pass the test case 0.6418459415435791
        if (num == 0.0) {
            return "0";
        }

        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            num *= 2;
            if (num >= 1.0) {
                sb.append('1');
                num -= 1.0;
                if (num == 0) {
                    break;
                }
            } else {
                sb.append('0');
            }
            if (sb.length() > 32) {
                return null;
            }
        }

        return sb.toString();
    }


    public static void main(String[] args) {
        BinaryRepresentation br = new BinaryRepresentation();
        String res = br.binaryRepresentation("0.5");
        System.out.println(res);
        String res2 = br.binaryRepresentation("0.6418459415435791");
        System.out.println(res2);
    }
}
