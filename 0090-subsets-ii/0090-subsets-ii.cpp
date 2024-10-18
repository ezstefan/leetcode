class Solution {
public:
    void findSubsequences(int ind, vector<int>& nums, vector<int>& path, vector<vector<int>> &ans) {
        ans.push_back(path);
        for (int i = ind; i < nums.size(); i++) {
            if( i != ind && nums[i] == nums[i-1]) {
                continue;
            }
            path.push_back(nums[i]);
            findSubsequences(i + 1, nums, path, ans);
            path.pop_back();

        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        findSubsequences(0, nums, path, ans);
        return ans;
        
    }
};