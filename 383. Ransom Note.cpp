class Solution {
public:
    // store magazine string characters in map with their freq. , traverse through ransom array apply conditions.
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>ump;
        int m = magazine.size();
        for(int i=0; i<m; i++){
            ump[magazine[i]]++;
        }
        bool ans = true;
        for(auto i:ransomNote){
            if(ump[i]==0||ump.find(i)==ump.end()){
                ans=false;
                break;
            }
           ump[i]--;
        }
        return ans;
    }
};