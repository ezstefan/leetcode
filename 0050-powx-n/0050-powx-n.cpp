class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if (x == 0 || x == 1) return x;  

        if (n < 0) {
            x = 1 / x;
            n = -(n + 1);  
            ans *= x;      
        }

        while (n > 0) {
            if (n % 2 == 1) {
                ans *= x;
                n -= 1;
            } else {
                n /= 2;
                x *= x;
            }
        }

        return ans;
    }
};
