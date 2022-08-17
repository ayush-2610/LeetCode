class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int>ump;
        string arr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // iterate through all the words make their morse expression store count of morse expression in a unordered map
        for(int i=0; i<words.size();i++){
            string s = "";
            for(int j=0; j<words[i].length(); j++){
                s = s+arr[words[i][j]-'a'];
            }
            ump[s]++;
        }
        return ump.size();
    }
};