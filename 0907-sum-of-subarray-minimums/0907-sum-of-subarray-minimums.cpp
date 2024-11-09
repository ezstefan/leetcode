class Solution {
public:
    void nextSmaller(vector<int>& arr, vector<int>& nse) {
        int n = arr.size();
        stack<int> st;

        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && arr[st.top()] > arr[j]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[j] = st.top();
            } else {
                nse[j] = n;  
            }
            st.push(j);
        }
    }

    void prevSmaller(vector<int>& arr, vector<int>& pse) {
        int n = arr.size();
        stack<int> st;

        for (int j = 0; j < n; j++) {
            while (!st.empty() && arr[st.top()] >= arr[j]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[j] = st.top();
            } else {
                pse[j] = -1;  
            }
            st.push(j);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n), pse(n);
        int total = 0;
        int mod = (int)(1e9 + 7);

        
        nextSmaller(arr, nse);
        prevSmaller(arr, pse);

        
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];  
            int right = nse[i] - i; 

            
            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }

        return total;
    }
};
