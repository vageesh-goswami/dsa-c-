#include <algorithm>
#include <cctype>
#include <iostream>
#include <unordered_map>
using namespace std;

// Basic implementation: reverse a string.
string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// Sample Problem 1: Check palindrome (ignoring non-alphanumeric and case).
// Approach: Two pointers from both ends.
bool isPalindrome(const string& s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        while (l < r && !isalnum((unsigned char)s[l])) l++;
        while (l < r && !isalnum((unsigned char)s[r])) r--;
        if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r])) return false;
        l++, r--;
    }
    return true;
}

// Sample Problem 2: First non-repeating character.
// Approach: Count frequencies, then scan again.
char firstUniqueChar(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    for (char c : s) {
        if (freq[c] == 1) return c;
    }
    return '#';
}

// Sample Problem 3: Check anagram.
// Approach: Frequency counting for lowercase English letters.
bool isAnagram(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    int cnt[26] = {0};
    for (char c : a) cnt[c - 'a']++;
    for (char c : b) cnt[c - 'a']--;
    for (int x : cnt) if (x != 0) return false;
    return true;
}

int main() {
    cout << "Reverse of code: " << reverseString("code") << "\n";
    cout << "Palindrome check: " << (isPalindrome("A man, a plan, a canal: Panama") ? "Yes" : "No") << "\n";
    cout << "First unique in 'aabbcdde': " << firstUniqueChar("aabbcdde") << "\n";
    cout << "Anagram (listen/silent): " << (isAnagram("listen", "silent") ? "Yes" : "No") << "\n";
    return 0;
}
