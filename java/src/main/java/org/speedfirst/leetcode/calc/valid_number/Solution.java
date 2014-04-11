package org.speedfirst.leetcode.calc.valid_number;

/**
 * Created by jiankuan on 12/4/14.
 */
public class Solution {
    enum State {
        Start,
        Symbol,
        Int,
        FirstPoint, // if "." appears before any digit, such as ".8", "+.8"
        Point,
        Frac,
        Exp,
        ExpSymbol,
        ExpInt
    }

    public boolean isNumber(String s) {
        if (s == null) {
            return false;
        }

        s = s.trim();
        if (s == "") {
            return false;
        }

        State state = State.Start;
        char[] chars = s.toCharArray();
        for (char c : chars) {
            switch (state) {
                case Start:
                    if (isSymbol(c)) {
                        state = State.Symbol;
                    } else if (isDigit(c)) {
                        state = State.Int;
                    } else if (c == '.') {
                        state = State.FirstPoint;
                    } else {
                        return false;
                    }
                    break;
                case Symbol:
                    if (isDigit(c)) {
                        state = State.Int;
                    } else if (c == '.') {
                        state = State.FirstPoint;
                    } else {
                        return false;
                    }
                    break;
                case Int:
                    if (isDigit(c)) {
                        // does nothing
                    } else if (c == '.') {
                        state = State.Point;
                    } else if (isExp(c)) {
                        state = State.Exp;
                    } else {
                        return false;
                    }
                    break;
                case FirstPoint:
                    if (isDigit(c)) {
                        state = State.Frac;
                    } else {
                        return false;
                    }
                    break;
                case Point:
                    if (isDigit(c)) {
                        state = State.Frac;
                    } else if (isExp(c)) {
                        state = State.Exp;
                    } else {
                        return false;
                    }
                    break;
                case Frac:
                    if (isDigit(c)) {
                        // does nothing
                    } else if (isExp(c)) {
                        state = State.Exp;
                    } else {
                        return false;
                    }
                    break;
                case Exp:
                    if (isDigit(c)) {
                        state = State.ExpInt;
                    } else if (isSymbol(c)) {
                        state = State.ExpSymbol;
                    } else {
                        return false;
                    }
                    break;
                case ExpSymbol:
                    if (isDigit(c)) {
                        state = State.ExpInt;
                    } else {
                        return false;
                    }
                    break;
                case ExpInt:
                    if (isDigit(c)) {
                        // does nothing
                    } else {
                        return false;
                    }
                    break;
            }
        }

        if (state == State.Int || state == State.Point || state == State.Frac || state == State.ExpInt) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isDigit(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        } else {
            return false;
        }
    }

    public boolean isSymbol(char c) {
        if (c == '+' || c == '-') {
            return true;
        } else {
            return false;
        }
    }

    public boolean isExp(char c) {
        if (c == 'e' || c == 'E' || c == 'd' || c == 'D') {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        boolean res = sol.isNumber(".2e81");
        System.out.println(res);
    }
}
