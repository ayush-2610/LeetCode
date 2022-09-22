class Solution {
public:
    // ALGO - self explanatory if left wall is smaller than right wall then icrease left pointer else decrease right pointer
    // beacause i want bigger container than current so i need big walls cause width is decreasing
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int ans=INT_MIN;
        while(i<j){
            ans = max(ans,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};