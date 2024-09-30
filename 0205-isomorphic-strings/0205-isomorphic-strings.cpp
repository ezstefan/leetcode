class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> ss;
        for (int i = 0; i < s.size(); i++) {
            if(ss.find(s[i]) == ss.end()) {
                for (auto it = ss.begin(); it != ss.end(); it++) {
                    if(it->second == t[i]) {
                        return false;
                    }
                }
                ss[s[i]] = t[i];
            }
            else{
                    if(ss[s[i]] != t[i]) {
                        return false;
                    }
                }
                
        }
        return true;
        
    }
};