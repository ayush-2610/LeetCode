class Solution {
public:
      void merge(vector<int>&nums,int low,int high,int mid,int &ans)
    {
        int i=low;
        int j=mid+1;
        
        vector<int>temp(high-low+1);
        
        while(i<=mid and j<=high)
        {
            if((long)nums[i]>(long)2*nums[j])
            {
                ans+=(mid-i+1); //if an elem satisfies condition(in left array i.e low to mid) then all elem in the low to mid
                //will satisfy
                j++;
            }
            else
            {
                i++;
            }
        }
        i=low;
        j=mid+1;
        int k=0;
        while(i<=mid and j<=high)
        {
            if(nums[i]<nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
            {
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid)
            temp[k++]=nums[i++];
        while(j<=high)
            temp[k++]=nums[j++];
        // this is an another variation of merge sort compare in my sorting Algo repo
        // in this we created temp array and store values in it and below copy those values in nums array
        for(i=low;i<=high;i++)
            nums[i]=temp[i-low];
    }
    void mergeSort(vector<int>&nums,int low,int high,int &ans)
    {
        if(low<high)// when 
        {
            int mid=(low+high)/2;
            mergeSort(nums,low,mid,ans);
            mergeSort(nums,mid+1,high,ans);
            
            merge(nums,low,high,mid,ans);
        }
    }
    int reversePairs(vector<int>& nums) {
        
        int n=nums.size();
        
        int ans=0;
        mergeSort(nums,0,n-1,ans);
        return ans;
    }
};