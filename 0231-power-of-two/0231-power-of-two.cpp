class Solution {
public:
    bool isPowerOfTwo(int n) {
        string binary = "";

        while(n > 0) {
            if(n % 2 == 1) {
                binary += '1';
            } else {
                binary += '0';
            }
            n = n / 2;
        }

        reverse(binary.begin(), binary.end());
        int count = 0;

        for (int i = binary.size() - 1; i >= 0; i--) {
            if(binary[i] == '1') {
                count++;
                
                if(count > 1) {
                    return false; 
                }
            } 
        }

        if (count == 0) {
            return false;
        }

        return count == 1;
    }
};
