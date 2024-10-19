class Solution {
public:
    void findCombinations(int ind, int target, int k, vector<int>& path, vector<vector<int>>& result) {
        
        if (target == 0 && path.size() == k) {
            result.push_back(path);
            return;
        }

        if (path.size() > k || target < 0) {
            return;
        }

        for (int i = ind; i <= 9; i++) {
            path.push_back(i);
            
            findCombinations(i + 1, target - i, k, path, result);
            
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        findCombinations(1, n, k, path, result);  
        return result;
    }
};
