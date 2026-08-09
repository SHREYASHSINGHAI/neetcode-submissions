class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // Stores frequencies of 'A'-'Z' in current window
        int left = 0;
        int max_freq = 0;   // Frequency of the most repeated character in current window
        int max_length = 0;

        for (int right = 0; right < s.length(); right++) {
            // Add current character to frequency array
            count[s[right] - 'A']++;
            
            // Track the maximum frequency seen in the window
            max_freq = max(max_freq, count[s[right] - 'A']);

            // Window size = (right - left + 1)
            // Number of replacements needed = Window size - max_freq
            // Shrink window if replacements needed exceed k
            while ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            // Update maximum valid length found
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};