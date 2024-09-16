class Solution {
public:

      bool isPalindrome(string s) {
        string normalized = normalize(s);
        return isPalindromeRec(normalized, 0, normalized.size() - 1);
    }

    string normalize(const string &s) {
        string normalized;
        for (char c : s) {
            if (isalnum(c)) {
                normalized += tolower(c);
            }
        }
        return normalized;
    }

    bool isPalindromeRec(const string &s, int left, int right) {
        if (left >= right) return true;
        if (s[left] != s[right]) return false;
        return isPalindromeRec(s, left + 1, right - 1);
    }
};