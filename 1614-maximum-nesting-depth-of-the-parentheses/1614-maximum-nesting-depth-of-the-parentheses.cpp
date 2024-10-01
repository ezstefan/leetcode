class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int curr = 0;

        for(auto c : s) {
            if( c == '(') {
                curr++;
            }
            else if ( c== ')') {
                maxi = max(maxi, curr);
                curr--;
            }
        }
        return maxi;
        
    }
};