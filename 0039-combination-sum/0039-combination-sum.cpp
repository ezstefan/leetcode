class Solution {
public:

    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& path) {
        if(ind == arr.size()) {
            if(target == 0) {
                ans.push_back(path);
            }
            return;
        }

        if(arr[ind] <= target) {
            path.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, path);
            path.pop_back();
        }
        findCombination(ind + 1, target, arr, ans, path);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        findCombination(0,target,candidates,ans,path);
        return ans;

    }
};