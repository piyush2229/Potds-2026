class Solution {
  public:
    int atmostK(vector<int>&arr,int k){
        int left=0;
        int ans=0;
        int n=arr.size();
        int count=0;
        for(int right=0;right<n;right++){
            if(arr[right]%2==1){
                count++;
            }
            while(count>k){
                if(arr[left]%2==1)count--;
                left++;
            }
            ans+=right-left+1;
        
            
        }
        return ans;
    }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return atmostK(arr,k)-atmostK(arr,k-1);
    }
};
// calculate number of subarrays with at most k odd numbers
// use sliding window approach
// for each right pointer, move left pointer to maintain at most k odd numbers
// count number of valid subarrays ending at right pointer
// return difference between number of subarrays with at most k odd numbers and at most k-1 odd numbers