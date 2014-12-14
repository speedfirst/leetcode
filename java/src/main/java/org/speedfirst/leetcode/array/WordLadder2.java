package org.speedfirst.leetcode.array;

import java.util.*;

/**
 * @author jiankuan
 * @date 12/12/14
 */

class WordLadder2 {

    class Node {

        public Node(String word, int len) {
            this.word = word;
            this.len = len;
        }

        public void addPrev(String word) {
            prevs.add(word);
        }

        public String word;
        public int len;
        public List<String> prevs = new LinkedList<String>();
    }

    public String replace(String str, int idx, char c) {
        char[] chars = str.toCharArray();
        chars[idx] = c;
        return new String(chars);
    }

    public List<List<String>> findLadders(String start, String end, Set<String> dict) {
        Map<String, Node> wordMap = new HashMap<>();
        Queue<Node> queue = new LinkedList<>();
        Node startNode = new Node(start, 1);
        wordMap.put(start, startNode);
        queue.offer(startNode);
        while (!queue.isEmpty()) {
            Node curNode = queue.poll();
            String curWord = curNode.word;
            for (int i = 0; i < curWord.length(); i++) {
                for (char c = 'a'; c < 'z'; c++) {
                    if (curWord.charAt(i) == c) continue;
                    String nextWord = replace(curWord, i, c);
                    if (dict.contains(nextWord)) {
                        if (!wordMap.containsKey(nextWord)) {
                            Node node = new Node(nextWord, curNode.len + 1);
                            wordMap.put(nextWord, node);
                            node.addPrev(curWord);
                            queue.offer(node);
                        } else {
                            Node node = wordMap.get(nextWord);
                            if (node.len == curNode.len + 1) {
                                node.addPrev(curWord);
                            }
                        }
                    }
                }
            }
        }

        List<List<String>> res = new LinkedList<>();
        genResult(wordMap, end, start, new LinkedList<>(), res);
        return res;
    }

    public void genResult(Map<String, Node> wordMap, String curWord, String startWord, List<String> curSeq, List<List<String>> res) {
        curSeq.add(0, curWord);
        if (curWord.equals(startWord)) {
            res.add(new ArrayList<>(curSeq));
        } else {
            for (String prevWord: wordMap.get(curWord).prevs) {
                genResult(wordMap, prevWord, startWord, curSeq, res);
            }
        }
        curSeq.remove(0);
    }

    public static void main(String[] args) {
        String[] dictWords = new String[] {"hot","cog","dog","tot","hog","hop","pot","dot"};
        Set<String> dict = new HashSet<String>(Arrays.asList(dictWords));
        WordLadder2 sol = new WordLadder2();
        List<List<String>> res = sol.findLadders("hot", "dog", dict);
        for (List<String> seq: res) {
            StringBuilder sb = new StringBuilder();
            for (String word: seq) {
                sb.append(word);
                sb.append(" ");
            }
            System.out.println(sb.toString());
        }
    }
}