class Solution {
public:
    int hammingWeight(int n) {
        string binary = "";
        while(n>0) {
            if(n%2 == 1) {
                binary = '1' + binary;
            }
            else{
                binary = '0' + binary;
            }
            n = n/2;
        }
        int cnt = 0;

        for(int i = binary.size(); i >=0; i--) {
            if(binary[i] == '1') {
                cnt++;
            }
        }
        return cnt;
        
    }
};