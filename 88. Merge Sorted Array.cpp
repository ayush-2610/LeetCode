class Solution {
public:
    //Algo = Make new array copy m elements of nums1 to array then from array and nums2 select min one by
    //       one and assign in nums1 array and at last if any elements left in array or nums2 traverse them
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m+n==1){ // see the constraints if m==0 copy single element of nums2 otherwise dont do anything
            if(m==0){
            nums1[0]=nums2[0];
            return;}
            else return;
        }
        int arr[m+1]; // m+1 because if m == 0 then error comes
        for(int i=0; i<m; i++){
            arr[i] = nums1[i];
        }
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(arr[i]<=nums2[j]){
                nums1[k] = arr[i];
                k++;
                i++;
            }
            else{
                nums1[k] = nums2[j];
                j++;
                k++;
            }
        }
        if(i!=m){
            while(i!=m){
                nums1[k] = arr[i];
                i++;
                k++;
            }
        }
        else{
            while(j!=n){
                nums1[k] = nums2[j];
                j++;
                k++;
            }
        }
    }
};