// to find Longest Substring Without Repeating Characters
#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0, start = 0;

    for (int end = 0; end < s.size(); end++) {
        char currentChar = s[end];

        // If the character is already in the map, move the start pointer to the right of the last occurrence
        if (charIndexMap.find(currentChar) != charIndexMap.end()) {
            start = max(start, charIndexMap[currentChar] + 1);
        }

        // Update the latest index of the current character
        charIndexMap[currentChar] = end;

        // Calculate the maximum length
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}