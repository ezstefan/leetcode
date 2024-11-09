class Solution {
public:
    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
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
        return nse;
    }

    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
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
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        int mod = (int)(1e9 + 7);

        
        vector<int> nse = nextSmaller(arr);
        vector<int> pse = prevSmaller(arr);

        
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];  
            int right = nse[i] - i; 

            
            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }

        return total;
    }
};
