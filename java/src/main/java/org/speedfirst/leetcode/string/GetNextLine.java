package org.speedfirst.leetcode.string;

import java.io.IOException;
import java.io.InputStream;

/**
 * Given a "get1K" method, implement a "getNextLine" method.
 *
 * Note:
 * 1) manage buffer
 * 2) deal with the case is one line is larger than 1k
 * 3) deal with empty line
 * 4) deal with eof
 *
 * Created by jiankuan on 1/15/15.
 */
public class GetNextLine {

    private InputStream input = GetNextLine.class.getResourceAsStream("test-get-next-line.txt");

    private byte[] buffer = new byte[1024];

    public int get1K(byte[] userBuffer) throws IOException {
        int count = input.read(buffer);
        if (count == -1) {
            return -1;
        }
        System.arraycopy(buffer, 0, userBuffer, 0, count);
        return count;

    }
    // ====================== you implement here ====================

    byte[] mybuffer = new byte[1024];
    int mybufStart = 0;
    int mybufLen = 0;


    public String getNextLine() throws IOException {
        if (mybufLen == -1) { // eof
            return "(eof)";
        }

        if (mybufLen == 0) {
            mybufLen = get1K(mybuffer);
            mybufStart = 0;
        }

        StringBuilder sb = new StringBuilder();
        while (true) {
            boolean found = false;

            if (mybufLen == -1) {
                if (sb.length() > 0) {
                    return sb.toString();
                } else {
                    return "(eof)";
                }
            }

            int mybufEnd = mybufStart + mybufLen;
            for (; mybufStart < mybufEnd; mybufStart++, mybufLen--) {
                if (mybuffer[mybufStart] == '\n') {
                    found = true;
                    break;
                }
                sb.append((char) mybuffer[mybufStart]);
            }

            if (found) {
                mybufLen--;
                mybufStart++; // skip the \n
                return sb.toString();
            } else {
                mybufLen = get1K(mybuffer);
                mybufStart = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        GetNextLine gnl = new GetNextLine();
        for (int i = 0; i < 40; i++) {
            System.out.println(gnl.getNextLine());
        }
    }
}
