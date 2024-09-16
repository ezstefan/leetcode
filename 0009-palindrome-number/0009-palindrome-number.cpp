class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
      int revn = 0;
      int dup = x;

        while (x != 0) {
            long ld = x % 10;
            if (revn > (INT_MAX - ld) / 10 || revn < (INT_MIN - ld) / 10) {
                return 0; 
            }
            revn = (revn * 10) + ld;
            x = x / 10;
        }

      return revn == dup;
    }
}; 