class Solution {
public:
    // ALGO - String stream is used mostly when string or string items is to be converted in some 
    // other data type it gives false results if string only contains blank spaces it  even consider 
    // full stops 
    int myAtoi(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ') count++;
        }
        if(count == s.length()) return 0;
        stringstream ss(s);
        int ans;
        ss >> ans;
        return ans;
    }
};