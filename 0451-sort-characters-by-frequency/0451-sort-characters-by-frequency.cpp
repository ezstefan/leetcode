class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        vector<pair<int,char>> v;
        string ans = "";

        for (auto ch : s) {
            mpp[ch]++;
        }
        for (auto i : mpp) {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), greater<pair<int,char>>());

        for (auto i : v) {
            while(i.first--) {
                ans += i.second;
            }
        }
        return ans;
        
    }
};