class Solution {
public:

    void findSubsequences(int ind, vector<int>& arr, int target, vector<int>& path, vector<vector<int>>& result) {

        if(target == 0) {
                result.push_back(path);
                return;
            }

            for(int i = ind; i < arr.size(); i++) {
                if(i > ind && arr[i] == arr[i-1]) {
                    continue;
                }
                if(arr[i] > target) {
                    break;
                }
                path.push_back(arr[i]);
                findSubsequences(i + 1, arr, target - arr[i], path, result);
                path.pop_back();
            }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        sort(candidates.begin(),candidates.end());
        findSubsequences(0, candidates, target, path, result);
        return result;
        
    }
};