class Solution {
    int countSubarraysWithMaxSum(vector<int>& nums, int maxSum) {
        int n = nums.size();
        int subarrayCount = 1;
        long long currentSum = 0;

        for(int i = 0; i < n; i++) {
            if (currentSum + nums[i] <= maxSum) {
                currentSum += nums[i];
            }
            else {
                subarrayCount++;
                currentSum = nums[i];
            }
        }
        return subarrayCount;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int subarrayCount = countSubarraysWithMaxSum(nums, mid);

            if (subarrayCount > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};
