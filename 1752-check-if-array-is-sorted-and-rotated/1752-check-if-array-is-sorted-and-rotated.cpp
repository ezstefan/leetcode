class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            // Compare current element with the previous one in a circular manner
            if (nums[i] < nums[(i - 1 + n) % n]) {
                count++;
            }
            // If there is more than one place where the order is broken, return false
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};