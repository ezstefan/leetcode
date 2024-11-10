class Solution {
public:
    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && arr[st.top()] < arr[j]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[j] = st.top();
            } else {
                nge[j] = n;
            }
            st.push(j);
        }
        return nge;
    }

    vector<int> prevGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n);
        stack<int> st;

        for (int j = 0; j < n; j++) {
            while (!st.empty() && arr[st.top()] <= arr[j]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[j] = st.top();
            } else {
                pge[j] = -1;
            }
            st.push(j);
        }
        return pge;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;

        vector<int> nge = nextGreater(arr);
        vector<int> pge = prevGreater(arr);

        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total = total + (left * right * 1LL * arr[i]);
        }

        return total;
    }

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

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;

        vector<int> nse = nextSmaller(arr);
        vector<int> pse = prevSmaller(arr);

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = total + (left * right * 1LL * arr[i]);
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long sumMax = sumSubarrayMaxs(nums);
        long long sumMin = sumSubarrayMins(nums);

        return sumMax - sumMin;
    }
};
