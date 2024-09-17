class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        int maxFreq = 1;
        int left = 0;
        long long total = 0; 

        for (int right = 1; right < nums.size(); ++right) {
            total += (long long)(nums[right] - nums[right - 1]) * (right - left);

            while (total > k) {
                total -= nums[right] - nums[left];
                left++;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};