class Solution {
    long long computeTotalSum(int n, int index, int peak) {
        long long sum = peak; 

        // Calculate the sum of the left side
        int leftLen = index; // Number of elements on the left side
        if (peak > leftLen) {
            sum += (long long)(peak - 1 + (peak - leftLen)) * leftLen / 2;
        } else {
            sum += (long long)(peak - 1) * peak / 2 + (leftLen - (peak - 1));
        }

        // Calculate the sum of the right side
        int rightLen = n - index - 1; 
        if (peak > rightLen) {
            sum += (long long)(peak - 1 + (peak - rightLen)) * rightLen / 2;
        } else {
            sum += (long long)(peak - 1) * peak / 2 + (rightLen - (peak - 1));
        }

        return sum;
    }
public:
    int maxValue(int n, int index, int maxSum) {
       int low = 1, high = maxSum;
        int result = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalSum = computeTotalSum(n, index, mid);

            if (totalSum <= maxSum) {
                result = mid; 
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        return result;
    }
};