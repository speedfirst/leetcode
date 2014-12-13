package org.speedfirst.leetcode.array;

/**
 * @author jiankuan
 * @date 12/13/14
 */
public class WordSearch {

    public boolean searchWord(char[][] board, boolean[][] visited, int w, int h, int curX, int curY, int curWordIdx, String word) {
        char c = word.charAt(curWordIdx);
        if (board[curX][curY] != c) {
            return false;
        }

        if (curWordIdx == word.length() - 1) {
            return true;
        }

        visited[curX][curY] = true;
        if (curX > 0 && !visited[curX - 1][curY] && searchWord(board, visited, w, h, curX - 1, curY, curWordIdx + 1, word)) return true;
        if (curX < h - 1 && !visited[curX + 1][curY] && searchWord(board, visited, w, h, curX + 1, curY, curWordIdx + 1, word)) return true;
        if (curY > 0 && !visited[curX][curY - 1] && searchWord(board, visited, w, h, curX, curY - 1, curWordIdx + 1, word)) return true;
        if (curY < w - 1 && !visited[curX][curY + 1] &&  searchWord(board, visited, w, h, curX, curY + 1, curWordIdx + 1, word)) return true;
        visited[curX][curY] = false;
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int h = board.length;
        int w = board[0].length;

        boolean[][] visited = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (searchWord(board, visited, w, h, i, j, 0, word)) {
                    return true;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        char[][] board = new char[1][1];
        board[0][0] = 'a';
        WordSearch ws = new WordSearch();
        boolean res = ws.exist(board, "a");
        System.out.println(res);
    }
}
