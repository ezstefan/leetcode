class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal; 
        int cnt = 0;

        while (ans > 0) {
            cnt += (ans & 1); 
            ans = ans >> 1;    
        }

        return cnt;
    }
};
