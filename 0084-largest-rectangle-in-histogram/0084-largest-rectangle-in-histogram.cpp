class Solution {
public:
    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nse[i] = st.top();
            }
            else{
                nse[i] = n;
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.empty()) {
                pse[i] = st.top();
            }
            else{
                pse[i] = -1;
            }
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse = nextSmaller(heights);
        vector<int> pse = prevSmaller(heights);
        int maxi = 0;

        for(int i = 0; i<n; i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;

        
    }
};