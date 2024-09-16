class Solution {
public:
    long reverse(long x) {
        long revn = 0;

        while (x != 0) {
            long ld = x % 10;
            if (revn > (INT_MAX - ld) / 10 || revn < (INT_MIN - ld) / 10) {
                return 0; 
            }
            revn = (revn * 10) + ld;
            x = x / 10;
        }

       return revn;
    }
}; 
