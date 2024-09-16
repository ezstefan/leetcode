class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;

        string temp;
        string ans;

        while (left <= right) {
            char ch = s[left];

            if (ch != ' ') {
                temp += ch;  
            } 
            else if (ch == ' ' && !temp.empty()) {
                if (!ans.empty()) ans = temp + " " + ans;  
                else ans = temp;  
                temp = "";  
            }
            left++;
        }

        
        if (!temp.empty()) {
            if (!ans.empty()) ans = temp + " " + ans;
            else ans = temp;
        }

        return ans;
    }
};
