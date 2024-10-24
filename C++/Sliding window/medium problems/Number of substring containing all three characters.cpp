class Solution {
public:
    // Function to count the number of substrings containing all three characters 'a', 'b', and 'c'.
    int numberOfSubstrings(string s) {
        // Initialize an array to store the last seen positions of 'a', 'b', and 'c'.
        int lastSeenPositions[3] = {-1, -1, -1};
      
        // Initialize the answer to 0.
        int substringCount = 0;
      
        // Iterate over the string.
        for (int index = 0; index < s.size(); ++index) {
            // Update the last seen position for the current character.
            lastSeenPositions[s[index] - 'a'] = index;
          
            // Find the smallest index among the last seen positions of 'a', 'b', and 'c'.
            // Add 1 because indices are 0-based, and we're interested in the number of elements.
            int minLastSeenPosition = min(lastSeenPositions[0], 
                                          min(lastSeenPositions[1], lastSeenPositions[2])) + 1;
          
            // Add the number of valid substrings ending with the current character.
            // This is possible because any substring ending at the current index
            // and starting before or at the smallest last seen index will contain all three characters.
            substringCount += minLastSeenPosition;
        }
      
        // Return the total count of valid substrings.
        return substringCount;
    }
};