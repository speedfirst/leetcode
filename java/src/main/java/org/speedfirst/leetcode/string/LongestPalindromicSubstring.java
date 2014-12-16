package org.speedfirst.leetcode.string;

/**
 * @author jiankuan
 * @date 12/16/14
 */
public class LongestPalindromicSubstring {
    public String maxPalindrome(String s, int centerToLeft, int centerToRight) {
        // even if centerToRight == s.length() (out of bound), we can still get the correct palindrome ""
        int left = centerToLeft;
        int right = centerToRight;

        while (left >= 0 && right <= s.length() - 1) {
            if (s.charAt(left) != s.charAt(right)) break;
            left--;
            right++;
        }

        // here is a little trick, after the loop, right must greater than left, so the substring will always succeed
        return s.substring(left + 1, right);
    }
    public String longestPalindrome(String s) {
        if (s.length() == 0 || s.length() == 1) {
            return s;
        }

        String maxPalindrome = "";
        for (int i = 0; i < s.length(); i++)  {
            // expand from s[i];
            String palindrome = maxPalindrome(s, i, i);
            if (palindrome.length() > maxPalindrome.length()) {
                maxPalindrome = palindrome;
            }

            // expand from the gap between s[i], s[i + 1]
            palindrome = maxPalindrome(s, i, i + 1);
            if (palindrome.length() > maxPalindrome.length()) {
                maxPalindrome = palindrome;
            }
        }

        return maxPalindrome;
    }
}
