class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        string left = "";
        char middle = '\0';

        // Build the left half in sorted order
        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2 == 1) {
                middle = 'a' + i;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (middle != '\0')
            return left + middle + right;

        return left + right;
    }
};