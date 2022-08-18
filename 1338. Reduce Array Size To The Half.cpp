class Solution {
public:
    // this can also be done through priority queue see one of the submission
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n = arr.size();
        for(int i=0; i<n; i++) mp[arr[i]]++;
        vector<int>v;
        for(auto it:mp)v.push_back(it.second);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());  // sorting with greater int because we want to delete min unique numbers
        int curr=0;
        int ans=0;
        for(auto i=0; i<v.size();i++){
            curr+=v[i];
            ans++;
            if(curr>=n/2)
                break;
        }
        return ans;
    }
};