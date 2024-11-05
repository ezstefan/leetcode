class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        vector<int> nge(n,-1);
        unordered_map<int,int> ngeMap;

        for(int i = n-1; i >=0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nge[i] = st.top();
            }
            else{
                nge[i] = -1;
            }
            st.push(nums2[i]);
        }

        for(int i =0; i<n; i++) {
            ngeMap[nums2[i]] = nge[i];
        }

        vector<int> result;

        for(int num : nums1) {
            result.push_back(ngeMap[num]);
        }
        return result;
        
    }
};