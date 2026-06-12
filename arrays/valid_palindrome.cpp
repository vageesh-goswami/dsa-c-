#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// LeetCode 125: Valid Palindrome
// Given a string s, determine if it is a palindrome, considering only alphanumeric
// characters and ignoring cases.

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        // Skip non-alphanumeric characters from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    // Test case 1
    string s1 = "A man, a plan, a canal: Panama";
    cout << "Test 1 - Is Valid Palindrome: " << (isPalindrome(s1) ? "true" : "false") << "\n";

    // Test case 2
    string s2 = "race a car";
    cout << "Test 2 - Is Valid Palindrome: " << (isPalindrome(s2) ? "true" : "false") << "\n";

    // Test case 3
    string s3 = " ";
    cout << "Test 3 - Is Valid Palindrome: " << (isPalindrome(s3) ? "true" : "false") << "\n";

    // Test case 4
    string s4 = "0P";
    cout << "Test 4 - Is Valid Palindrome: " << (isPalindrome(s4) ? "true" : "false") << "\n";

    return 0;
}
