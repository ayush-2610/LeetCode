class Solution {
public:
    //  Algo - for the array first put all elements with their freq. then again traverse the array if you get
    //      an element find for element/2 or element*2 if either is present move forwad make pair of element and its counter part drecrease freq of each by 1 and move forward;
    // NOTE - sort the array first and use element*2 case first to make sure smaller elements are eliminated first
    //     cause for the case [-16,-8,-32,-64] if you dont sort then -16 will make pair with -32 the -8 would 
    //         be left
             
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int>ump;
        for(auto i:arr){
            ump[i]++;
        }
        sort(arr.begin(),arr.end());
        // for(auto it:ump) cout<<it.first<<endl;
        vector<pair<int,int>>vec;
        for(auto it:arr){
             // cout<<it<<endl;
            if(ump.find(it)->second==0) continue;
            if((ump.find(it*2)!=ump.end()&&ump[it*2]!=0)  || (it%2==0&&ump.find(it/2)!=ump.end()&&ump[it/2]!=0)){
                
                if((ump.find(it*2)!=ump.end()&&ump[it*2]!=0)){
                    vec.push_back({it,it*2});
                    ump[it]--;
                    ump[it*2]--;
                }
                else{
                    vec.push_back({it,it/2});
                    ump[it]--;
                    ump[it/2]--;
                }
            }
            else {
                 cout<<it<<endl;
                return false;
            }
        }
        return true;
    }
};