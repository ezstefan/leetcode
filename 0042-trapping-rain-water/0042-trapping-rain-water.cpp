class Solution {
public:
    vector<int> leftMax(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n, 0);

        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }
        return prefixMax;
    }
    
    vector<int> rightMax(vector<int>& height) {
        int n = height.size();
        vector<int> suffixMax(n, 0);

        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }
        return suffixMax;
    }
    
    int trap(vector<int>& height) {
        int total = 0;
        int n = height.size();

        vector<int> leftMaxArr = leftMax(height);
        vector<int> rightMaxArr = rightMax(height);

        for (int i = 0; i < n; i++) {
            int leftMax = leftMaxArr[i];
            int rightMax = rightMaxArr[i];
            if (leftMax > height[i] && rightMax > height[i]) {
                total += min(leftMax, rightMax) - height[i];
            }
        }
        
        return total;
    }
};
