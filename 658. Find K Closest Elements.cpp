class Solution {
public:
    //ALGO - find element which is closest to the given x, take left pointer and right pointer and keep pushing values inside
    // the ans vector. then at last sort. 
    // this question can also be done by binary search. 
    // https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int l = 0,r = 0;
        int mini = INT_MAX;
        int index = 0;
        for(int i=0; i<arr.size();i++){
             // cout<<abs(arr[i]-x)<<" "; 
            if(abs(arr[i]-x)<mini){
                mini = abs(arr[i]-x);
                index = i;
            }
        }
        // cout<<" in :"<<index; 
        ans.push_back(arr[index]);
        k--;
        l = index-1;
        r = index+1;
        while(k){
            if(l<0 || r>(arr.size()-1)){
                 if(l>=0){
                ans.push_back(arr[l--]);
                k--;
            }
            else{
                ans.push_back(arr[r++]);
                k--;
            }
            }
            else if(x-arr[l]<=arr[r]-x){
                ans.push_back(arr[l]);
                l--;
                k--;
            }
            else{
                ans.push_back(arr[r]);
                r++;
                k--;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};