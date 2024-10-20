import java.util.*;

public class WordLadder {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) {
            return 0;
        }

        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        int level = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String currentWord = queue.poll();
                char[] currentChars = currentWord.toCharArray();

                for (int j = 0; j < currentChars.length; j++) {
                    char originalChar = currentChars[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        currentChars[j] = c;
                        String newWord = String.valueOf(currentChars);

                        if (newWord.equals(endWord)) {
                            return level + 1;
                        }

                        if (wordSet.contains(newWord)) {
                            queue.add(newWord);
                            wordSet.remove(newWord);
                        }
                    }
                    currentChars[j] = originalChar;
                }
            }
            level++;
        }
        return 0;
    }
}
