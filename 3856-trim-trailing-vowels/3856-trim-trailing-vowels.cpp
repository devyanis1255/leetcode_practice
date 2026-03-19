#include <iostream>
#include <string>

class Solution {
public:
    string trimTrailingVowels(string s) {
        // Start from the end of the string
        int i = s.length() - 1;
        
        // Loop backwards while the current character is a vowel
        while (i >= 0 && isVowel(s[i])) {
            i--;
        }
        
        // Return the substring from index 0 to length (i + 1)
        return s.substr(0, i + 1);
    }

private:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};