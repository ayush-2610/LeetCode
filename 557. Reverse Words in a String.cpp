class Solution {
public:
    // USING STRING STREAM
    string reverseWords(string s) {
        stringstream ss(s);
        string cur;
        string ans = "";
        while(ss >> cur){
            reverse(cur.begin(),cur.end());
            ans += cur + " ";
        }
        int n = ans.length();
        ans = ans.substr(0,n-1);
        return ans;
    }
};