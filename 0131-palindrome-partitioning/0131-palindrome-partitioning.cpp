class Solution {
public:

    bool isPalindrome(string s, int start, int end) {
        while( start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void partitionfunc(int ind, string s, vector<string>& path, vector<vector<string>>& result) {
        if(ind == s.size()) {
            result.push_back(path);
            return;
        }
        for(int i = ind; i < s.size(); i++) {
            if(isPalindrome(s, ind, i)) {
                path.push_back(s.substr(ind, i - ind + 1));
                partitionfunc(i+1, s, path, result);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        partitionfunc(0, s, path, result);
        return result;
        
    }
};